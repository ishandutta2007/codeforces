#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=109,inf=0x3f3f3f3f3f3f3f3f;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,b,f[2][1<<22];
struct node {int x,k,t;} a[N];
bool cmp(const node &a,const node &b) {return a.k<b.k;}

void upd(int &x,int y) {x=min(x,y);}

signed main() {
	n=read(), m=read(), b=read();
	rep(i,1,n) {
		a[i].x=read(), a[i].k=read(); int m=read();
		rep(j,1,m) a[i].t+=(1ll<<read()-1);
	}
	sort(a+1,a+n+1,cmp);
	int S=(1ll<<m)-1,d=0,ans=inf;
	rep(s,1,S) f[0][s]=inf;
	rep(i,0,n-1) {
		rep(s,0,S) f[d^1][s]=inf;
		rep(s,0,S) if(f[d][s]<inf) {
			upd(f[d^1][s|a[i+1].t],f[d][s]+a[i+1].x);
			upd(f[d^1][s],f[d][s]);
		}
		if(f[d^1][S]<inf) ans=min(ans,f[d^1][S]+a[i+1].k*b);
		d^=1;
	}
	printf("%lld\n",ans==inf?-1ll:ans);
	return 0;
}