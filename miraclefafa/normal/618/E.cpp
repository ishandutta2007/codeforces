#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
const double pi=acos(-1.);
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head
typedef complex<double> CD;

const int N=301000;
struct info {
	CD m,a;
	info() {}
	info(CD m,CD a):m(m),a(a) {}
}t[N*4];
int n,m,ty,x,y;
info operator + (const info &a,const info &b) {
	return info(a.m*b.m,b.a*a.m+a.a);
}
void build(int p,int l,int r) {
	if (l==r) t[p]=info(CD(1,0),CD(-1,0));
	else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		t[p]=t[p+p]+t[p+p+1];
	}
}
void modify(int p,int l,int r,int x,info c,int ty) {
	if (l==r) {
		if (ty==0) t[p]=c+t[p]; else t[p]=t[p]+c;
		return;
	} else {
		int md=(l+r)>>1;
		if (x<=md) modify(p+p,l,md,x,c,ty);
		else modify(p+p+1,md+1,r,x,c,ty);
		t[p]=t[p+p]+t[p+p+1];
	}
}
info query(int p,int l,int r,int x) {
	if (x==r) {
		return t[p];
	} else {
		int md=(l+r)>>1;
		if (x<=md) return query(p+p,l,md,x);
		else return t[p+p]+query(p+p+1,md+1,r,x);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	build(1,1,n);
	rep(i,0,m) {
		scanf("%d%d%d",&ty,&x,&y);
		if (ty==2) {
			double ang=-y*pi/180;
			modify(1,1,n,x,info(CD(cos(ang),sin(ang)),CD(0,0)),0);
		} else if (ty==1) {
			modify(1,1,n,x,info(CD(1,0),CD(-y,0)),1);
		}
		printf("%.10f %.10f\n",-real(t[1].a),-imag(t[1].a));
	}
}