#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define fi first
#define se second
#define eb emplace_back
#define bp __builtin_parity
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

int read() {
	int x=0,w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {x=x*10+c-'0'; c=getchar();}
	return x*w;
}

const int N=1e6+9;
int n,k,s[N];
struct node {int a,b;} c[N];

bool cmp(const node &x,const node &y) {return x.a+x.b==y.a+y.b?x.b>y.b:x.a+x.b>y.a+y.b;}

bool solve1() {
	if(n==1) {
		return k<=c[1].a;
	}
	if(k<=c[1].a) return 1;
	int p=k-c[1].b, q=c[1].a;
	if(p>q) return 0;
	int x=p;
	sort(c+2,c+n+1,cmp);
	s[n+1]=0;
	per(i,n,2) s[i]=max(s[i+1],c[i].a);
	if(x<=s[2]) return 1;
	rep(i,2,n-1) {
		x-=c[i].b; if(x>c[i].a) return 0;
		if(x<=s[i+1]) return 1;
	}
	return 0;
}
bool solve2() {
	if(n==1) return 0;
	if(n==2) return 0;
	if(k<=c[1].a) return 1;
	int p=k-c[1].b, q=c[1].a;
	if(p>q) return 0;
	int x=p;
	sort(c+2,c+n+1,cmp); swap(c[n-1],c[n]);
	s[n+1]=0;
	per(i,n,2) s[i]=max(s[i+1],c[i].a);
	if(x<=s[2]) return 1;
	rep(i,2,n-1) {
		x-=c[i].b; if(x>c[i].a) return 0;
		if(x<=s[i+1]) return 1;
	}
	return 0;
}

signed main() {
	int T=read();
	while(T--) {
		n=read(), k=read();
		rep(i,1,n) c[i].a=read(), c[i].b=read();
		bool ans=solve1()||solve2();
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}