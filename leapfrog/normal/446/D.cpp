//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=605;typedef long double ld;
int n,m,K,dg[N],a[N][N],cg[N],rbt,rb[N];ld gs[N][N+105];
struct mat
{
	ld a[105][105];inline ld* operator[](int x) {return a[x];}
	inline void operator!() {for(int i=0;i<=rbt;i++) for(int j=0;j<=rbt;j++) a[i][j]=0;}
	inline void operator~() {!*this;for(int i=0;i<=rbt;i++) a[i][i]=1;}
	inline mat operator*(mat b)
	{
		mat r;!r;for(int k=0;k<=rbt;k++)
			for(int i=0;i<=rbt;i++) for(int j=0;j<=rbt;j++) r[i][j]+=a[i][k]*b[k][j];
		return r;
	}
	inline mat operator^(int q) {mat r,x=*this;~r;for(;q;q>>=1,x=x*x) if(q&1) r=r*x;return r;}
}mt;
int main()
{
	read(n,m,K);for(int i=1;i<=n;i++) read(cg[i]);
	for(int i=1,x,y;i<=m;i++) read(x,y),a[x][y]++,a[y][x]++,dg[x]++,dg[y]++;
	for(int i=1;i<=n;i++) if(cg[i]) rb[i]=++rbt;
	for(int i=1;i<=n;i++)
	{
		gs[i][i]=-1;for(int j=1;j<=n;j++)
			(cg[j]?gs[i][n+rb[j]]:gs[i][j])+=a[i][j]*1.0/dg[i];
	}
	for(int i=1;i<=rbt;i++) gs[i+n][i+n+rbt]=1,gs[i+n][i+n]=1;
	for(int i=1;i<=n+rbt;i++)
	{
		int ps=i;for(int j=i+1;j<=n+rbt;j++) if(abs(gs[j][i])>abs(gs[ps][i])) ps=j;
		if(abs(gs[ps][i])<1e-9) continue;
		for(int j=1;j<=n+rbt+rbt;j++) swap(gs[i][j],gs[ps][j]);
		ld qw=gs[i][i];for(int j=i;j<=n+rbt+rbt;j++) gs[i][j]/=qw;
		for(int j=i+1;j<=n+rbt;j++) {ld qw=gs[j][i];for(int k=1;k<=n+rbt+rbt;k++) gs[j][k]-=gs[i][k]*qw;}
	}
	for(int i=n+rbt;i>=1;i--) for(int j=1;j<i;j++)
		{ld qw=gs[j][i];for(int k=1;k<=n+rbt+rbt;k++) gs[j][k]-=gs[i][k]*qw;}
	//for(int i=1;i<=n+rbt;i++) for(int j=1;j<=n+rbt+rbt;j++) printf("%.5Lf%c",gs[i][j],j==n+rbt+rbt?'\n':' ');
	for(int i=1;i<=rbt;i++) mt[0][i]=gs[1][n+rbt+i];
	for(int i=1;i<=n;i++) if(cg[i]) for(int j=1;j<=rbt;j++) mt[rb[i]][j]=gs[i][n+rbt+j];
	//for(int i=0;i<=rbt;i++) for(int j=0;j<=rbt;j++) printf("%.5Lf%c",mt[i][j],j==rbt?'\n':' ');
	return mt=mt^(K-1),printf("%.10Lf\n",mt[0][rb[n]]),0;
}