#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef double ld;
typedef long long ll;
typedef complex<ld> co;
const ld PI=atan2(0, -1);

vector<co> fft(vector<co> x, int d) {
	int n=x.size();
	for (int i=0;i<n;i++) {
		int u=0;
		for (int j=1;j<n;j*=2) {
			u*=2;
			if (i&j) u++;
		}
		if (i<u) {
			swap(x[i], x[u]);
		}
	}
	for (int m=2;m<=n;m*=2) {
		co wm=exp(co{0, d*2*PI/m});
		for (int k=0;k<n;k+=m) {
			co w=1;
			for (int j=0;j<m/2;j++) {
				co t=w*x[k+j+m/2];
				co u=x[k+j];
				x[k+j]=u+t;
				x[k+j+m/2]=u-t;
				w*=wm;
			}
		}
	}
	if (d==-1) {
		for (int i=0;i<n;i++) {
			x[i]/=n;
		}
	}
	return x;
}

vector<int> conv(vector<int> a, vector<int> b) {
	int as=a.size();
	int bs=b.size();
	vector<co> aa(as);
	vector<co> bb(bs);
	for (int i=0;i<as;i++) {
		aa[i]=a[i];
	}
	for (int i=0;i<bs;i++) {
		bb[i]=b[i];
	}
	int n=1;
	while (n<as+bs-1) n*=2;
	aa.resize(n*2);
	bb.resize(n*2);
	aa=fft(aa, 1);
	bb=fft(bb, 1);
	vector<co> c(2*n);
	for (int i=0;i<2*n;i++) {
		c[i]=aa[i]*bb[i];
	}
	c=fft(c, -1);
	c.resize(as+bs-1);
	vector<int> r(as+bs-1);
	for (int i=0;i<as+bs-1;i++) {
		r[i]=(int)round(c[i].real());
	}
	return r;
}

vector<int> get(vector<int> t, int k){
	if (k==1) return t;
	if (k%2==0){
		t=get(t, k/2);
		t=conv(t, t);
		for (int i=0;i<(int)t.size();i++){
			if (t[i]!=0) t[i]=1;
		}
		return t;
	}
	else{
		vector<int> b=get(t, k-1);
		t=conv(t, b);
		for (int i=0;i<(int)t.size();i++){
			if (t[i]!=0) t[i]=1;
		}
		return t;
	}
}

int main(){
	int n,k;
	scanf("%d %d", &n, &k);
	vector<int> t(1001);
	for (int i=0;i<n;i++){
		int a;
		scanf("%d", &a);
		t[a]=1;
	}
	t=get(t, k);
	for (int i=1;i<(int)t.size();i++){
		if (t[i]==1){
			printf("%d ", i);
		}
	}
	printf("\n");
}