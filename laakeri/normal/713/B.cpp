#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

//pair<pair<int, int>, pair<int, int> > r1 = {{1, 1}, {2, 2}};
//pair<pair<int, int>, pair<int, int> > r2 = {{3, 3}, {4, 4}};

int in(pair<pair<int, int>, pair<int, int> > qr, pair<pair<int, int>, pair<int, int> > re) {
	assert(qr.F.F<=qr.S.F);
	assert(qr.F.S<=qr.S.S);
	if (qr.F.F<=re.F.F&&re.S.F<=qr.S.F&&qr.F.S<=re.F.S&&re.S.S<=qr.S.S) return 1;
	return 0;
}

int tr=0;

int qr(int x1, int y1, int x2, int y2){
	if (tr==1) {
		swap(x1, y1);
		swap(x2, y2);
	}
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	int r;
	cin>>r;
	return r;
	//return in({{x1, y1}, {x2, y2}}, r1)+in({{x1, y1}, {x2, y2}}, r2);
}

void pr(int x1, int y1, int x2, int y2, int xx1, int yy1, int xx2, int yy2){
	if (tr==1) {
		swap(x1, y1);
		swap(x2, y2);
		swap(xx1, yy1);
		swap(xx2, yy2);
	}
	cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<xx1<<" "<<yy1<<" "<<xx2<<" "<<yy2<<endl;
	exit(0);
}

int n;

pair<pair<int, int>, pair<int, int> > fn(int yl, int yu){
	int mi=yl;
	int ma=yu;
	int x1=0;
	int y1=0;
	int x2=0;
	int y2=0;
	while (mi<=ma){
		int mid=(mi+ma)/2;
		if (qr(1, yl, n, mid)>=1){
			y2=mid;
			ma=mid-1;
		}
		else{
			mi=mid+1;
		}
	}
	if (y2==0) return {{0, 0}, {0, 0}};
	mi=yl;
	ma=y2;
	while (mi<=ma){
		int mid=(mi+ma)/2;
		if (qr(1, mid, n, y2)>=1){
			y1=mid;
			mi=mid+1;
		}
		else{
			ma=mid-1;
		}
	}
	if (y1==0) return {{0, 0}, {0, 0}};
	mi=1;
	ma=n;
	while (mi<=ma){
		int mid=(mi+ma)/2;
		if (qr(1, y1, mid, y2)>=1){
			x2=mid;
			ma=mid-1;
		}
		else{
			mi=mid+1;
		}
	}
	if (x2==0) return {{0, 0}, {0, 0}};
	mi=1;
	ma=x2;
	while (mi<=ma){
		int mid=(mi+ma)/2;
		if (qr(mid, y1, x2, y2)>=1){
			x1=mid;
			mi=mid+1;
		}
		else{
			ma=mid-1;
		}
	}
	if (x1==0) return {{0, 0}, {0, 0}};
	return {{x1, y1}, {x2, y2}};
}

void go() {
	int mi=1;
	int ma=n;
	int f1=0;
	int f2=0;
	while (mi<=ma){
		int mid=(mi+ma)/2;
		int r=qr(1, 1, n, mid);
		if (r==0){
			mi=mid+1;
		}
		else if(r==1){
			f1=mid;
			ma=mid-1;
		}
		else {
			ma=mid-1;
		}
	}
	mi=1;
	ma=n;
	while (mi<=ma){
		int mid=(mi+ma)/2;
		int r=qr(1, mid, n, n);
		if (r==0){
			ma=mid-1;
		}
		else if(r==1){
			f2=mid;
			mi=mid+1;
		}
		else {
			mi=mid+1;
		}
	}
	if (f1==0||f2==0) return;
	auto v1=fn(1, f1);
	auto v2=fn(f2, n);
	if (v1.F.F==0||v1.F.S==0||v1.S.F==0||v1.S.S==0) return;
	if (v2.F.F==0||v2.F.S==0||v2.S.F==0||v2.S.S==0) return;
	if (v1==v2) return;
	pr(v1.F.F, v1.F.S, v1.S.F, v1.S.S, v2.F.F, v2.F.S, v2.S.F, v2.S.S);
}

int main(){
	cin>>n;
	go();
	tr=1;
	go();
	assert(0);
}