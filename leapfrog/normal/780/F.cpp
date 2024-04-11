//
#include<bits/stdc++.h>
#define double long double
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,m;bitset<505>F[2][61][505],T,G;long long pw[65],res=0;
int main()
{
	read(n),read(m);
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),F[w][0][x][y]=1;
	for(int i=1;i<=60;i++) for(int x=1;x<=n;x++) for(int y=1;y<=n;y++)
	{
		if(F[0][i-1][x][y]) F[0][i][x]|=F[1][i-1][y];
		if(F[1][i-1][x][y]) F[1][i][x]|=F[0][i-1][y];
	}
	if(F[0][60][1].count()) return puts("-1"),0;else T[1]=1;
	int nw=0;pw[0]=1;for(int i=1;i<=60;i++) pw[i]=pw[i-1]<<1;
	for(int i=60;~i;i--)
	{
		G.reset();for(int j=1;j<=n;j++) if(T[j]) G|=F[nw][i][j];
		if(G.count()) nw^=1,T=G,res+=pw[i];
	}
	if(res>(long long)1e18) return puts("-1"),0;else return printf("%lld\n",res),0;
}