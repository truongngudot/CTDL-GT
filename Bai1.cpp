#include<iostream>
#include<string>
using namespace std;
struct Ngay { 
	int ngay, thang, nam; 
};
struct SinhVien { 
	int maSV; 
	string hoTen;
	char gioiTinh[20];
	Ngay ngaySinh;
	string diaChi;
	char lop[12];
	char khoa[7]; 
};
struct Node {
	SinhVien data;
	Node* link;
};
struct List { 
	Node *first;
	Node *last;
};
Node* CreateNode(SinhVien x)
{
	Node* p;
	p = new Node;
	if (p == NULL)  exit(1);
	p->data = x;
	p->link = NULL;
	return p;
}
void Nhap(SinhVien *a,int n) {
	a = new SinhVien[200];
	for (size_t i = 0; i < n; i++)
	{
		cout << "Nhap ma sv: ";
		cin >> a[i].maSV;
		cin.ignore();
		cout << "Nhap ho ten: ";
		getline(cin, a[i].hoTen);
		cout << "Nhap lop: ";
		cin >> a[i].lop;
		cout << "Nhap khoa: ";
		cin >> a[i].khoa;
		cout << "Nhap ngay sinh:";
		cin >> a[i].ngaySinh.ngay >> a[i].ngaySinh.thang >> a[i].ngaySinh.nam;
		cout << "Nhap gioi tinh: ";
		cin >> a[i].gioiTinh;
		cout << "Nhap dia chi: ";
		cin.ignore();
		getline(cin, a[i].diaChi);
	}
}
void ThemSV(SinhVien* a, int n) {
	n++;
	for (int  i =n-1; i >0 ; i--)
	{
		cout << "Nhap ma sv: ";
		cin >> a[i].maSV;
		cin.ignore();
		cout << "Nhap ho ten: ";
		getline(cin, a[i].hoTen);
		cout << "Nhap lop: ";
		cin >> a[i].lop;
		cout << "Nhap khoa: ";
		cin >> a[i].khoa;
		cout << "Nhap ngay sinh:";
		cin >> a[i].ngaySinh.ngay >> a[i].ngaySinh.thang >> a[i].ngaySinh.nam;
		cout << "Nhap gioi tinh: ";
		cin >> a[i].gioiTinh;
		cout << "Nhap dia chi: ";
		cin.ignore();
		getline(cin, a[i].diaChi);
	}
}
void XuatSV(SinhVien* a, int n) {
	a = new SinhVien[200];
	for (size_t i = 0; i < n; i++)
	{
		cout << "Ma sv: " << a[i].maSV << endl;
		cout << "Ho ten: "<<a[i].hoTen<<endl;
		cout << "Lop: "<< a[i].lop<<endl;
		cout << "Khoa: "<< a[i].khoa<<endl;
		cout << "Ngay sinh:"<< a[i].ngaySinh.ngay <<"/"<<a[i].ngaySinh.thang<<"/"<<  a[i].ngaySinh.nam<<endl;
		cout << "Gioi tinh: "<< a[i].gioiTinh<<endl;
		cout << "Nhap dia chi: "<< a[i].diaChi<<endl;
	}
}
void sapxep(SinhVien *a, int n) {
	a = new SinhVien[200];
	SinhVien tmp;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i].maSV > a[j].maSV) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
void Timkiem(SinhVien* a, int n) {
	a = new SinhVien[200];
	int t = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if ((a[i].ngaySinh.ngay == a[j].ngaySinh.ngay)&&(a[i].ngaySinh.thang == a[j].ngaySinh.thang)
				&&(a[i].ngaySinh.nam == a[j].ngaySinh.nam)) {
				cout << "Ma sv: " << a[i].maSV << endl;
				cout << "Ho ten: " << a[i].hoTen << endl;
				cout << "Lop: " << a[i].lop << endl;
				cout << "Khoa: " << a[i].khoa << endl;
				cout << "Ngay sinh:" << a[i].ngaySinh.ngay << "/" << a[i].ngaySinh.thang << "/" << a[i].ngaySinh.nam << endl;
				cout << "Gioi tinh: " << a[i].gioiTinh << endl;
				cout << "Nhap dia chi: " << a[i].diaChi << endl;
				t++;
			}
		}
	}
	if (t == 0) cout << "Khong co sinh vien cung ngay";
}
int main() {
	int n; cin >> n;
	SinhVien *an=new SinhVien[200];
	Nhap(an, n);
	sapxep(an, n);
	XuatSV(an, n);
	ThemSV(an, n);
	XuatSV(an, n);
	return 0;
}
