//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int Ca,n,idmx,idmn,rs[10005],mx[10005],mn[10005];char fgmx,fgmn;
inline int ask(int t,int i,int j,int x) {int v;return printf("? %d %d %d %d\n",t,i,j,x),fflush(stdout),read(v),v;}
inline void getmx(int a,int b)
{
	int rs=ask(1,a,b,n-1);mx[a]=rs;
	if(rs==n) fgmx=1,idmx=b;else if(rs==n-1) {rs=ask(1,b,a,n-1);if(rs==n) fgmx=1,idmx=a;}
}
inline void getmn(int a,int b)
{
	int rs=ask(2,a,b,1);mn[a]=rs;
	if(rs==1) fgmn=1,idmn=a;else if(rs==2) {rs=ask(2,b,a,1);if(rs==1) fgmn=1,idmn=b;}
}
inline void work(int a,int b)
{
	if(a==idmn) return rs[a]=1,rs[b]=ask(1,a,b,n-1),void();
	if(a==idmx) return rs[a]=n,rs[b]=ask(2,b,a,1),void();
	if(b==idmn) return rs[b]=1,rs[a]=ask(1,b,a,n-1),void();
	if(b==idmx) return rs[b]=n,rs[a]=ask(2,a,b,1),void();
	int res=ask(1,a,b,mn[a]);if(res==mn[a]) rs[a]=mx[a],rs[b]=mn[a];else rs[a]=mn[a],rs[b]=mx[a];
}
inline void solve()
{
	read(n),idmx=idmn=fgmx=fgmn=0;
	getmx(n,1);for(int i=1;i<n;i+=2) getmx(i,i+1);
	getmn(n,1);for(int i=1;i<n;i+=2) getmn(i,i+1);
	work(n,1);for(int i=1;i<n;i+=2) work(i,i+1);
	printf("! ");for(int i=1;i<=n;i++) printf("%d ",rs[i]);
	putchar('\n'),fflush(stdout);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}