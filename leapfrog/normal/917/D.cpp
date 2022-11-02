//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int P=1e9+7;int n,a[105][105],F[105][105],r[105],g[105],f[105],gt;
inline int pls(int x,int y) {return x+y>=P?x+y-P:x+y;}
inline void adde(int x,int y,int w) {F[x][x]=pls(F[x][x],w),F[x][y]=pls(F[x][y],P-w);}
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int solve(int k)
{
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) F[i][j]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i^j) adde(i,j,a[i][j]?k:1);
	int rs=1,tg=0;for(int i=1;i<n;i++)
	{
		if(!F[i][i]) for(int j=i+1;j<n;j++) if(F[i][j])
		{
			for(int k=1;k<n;k++) swap(F[i][k],F[j][k]);
			tg^=1;break;
		}
		for(int j=i;j<n;j++) if(F[j][i])
		{
			int iv=ksm(F[j][i]);rs=1ll*rs*F[j][i]%P;
			for(int k=i;k<n;k++) F[j][k]=1ll*F[j][k]*iv%P;
		}
		for(int j=i+1;j<n;j++) if(F[j][i]) for(int k=i;k<n;k++) F[j][k]=pls(F[j][k],P-F[i][k]);
	}
	for(int i=1;i<n;i++) rs=1ll*rs*F[i][i]%P;
	return tg?(P-rs)%P:rs;
}
inline void mul(int x) {g[gt+1]=0;for(int i=gt-1;~i;i--) g[i+1]=pls(g[i+1],g[i]),g[i]=1ll*g[i]*(P-x)%P;gt++;}
inline void div(int x) {int iv=ksm(x);for(int i=0;i<gt;i++) g[i]=(P-1ll*g[i]*iv%P),g[i+1]=pls(g[i+1],P-g[i]);gt--;}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),a[x][y]=a[y][x]=1;
	g[0]=gt=1;for(int i=1;i<=n;i++) r[i]=solve(i),mul(i);
	//for(int i=1;i<=n;i++) printf("%d : %d\n",i,r[i]);
	for(int i=1;i<=n;mul(i),i++)
	{
		div(i);int res=1;for(int j=1;j<=n;j++) if(i^j) res=1ll*res*(i-j+P)%P;
		res=1ll*r[i]*ksm(res)%P;for(int i=0;i<gt;i++) f[i]=(f[i]+1ll*res*g[i])%P;
	}
	for(int i=0;i<n;i++) printf("%d%c",f[i],i==n-1?'\n':' ');
	return 0;
}