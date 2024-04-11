//Coded by Katou_Umi on 2021.10.29 {{{
//
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
const int N=255;int n,m,a[N][N],hmx[N],lmx[N];
int fg[N*N],rs[N][N],lf[N],rg[N];
int main()
{
	read(n,m);for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) hmx[i]=max(hmx[i],a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) lmx[j]=max(lmx[j],a[i][j]);
	for(int i=1;i<=n;i++) fg[hmx[i]]|=1;
	for(int i=1;i<=m;i++) fg[lmx[i]]|=2;
	for(int k=n*m,x=0,y=0;k>=1;k--)
	{
		if(fg[k]==3) {rs[++x][++y]=k,lf[x]=rg[x]=y;continue;}
		else if(fg[k]==2) {rs[x][++y]=k,rg[x]=y;continue;}
		else if(fg[k]==1) {rs[++x][y]=k,lf[x]=rg[x]=y;continue;}
		int fg=0;for(int i=1;i<=x&&!fg;i++)
		{
			for(int j=lf[i]-1;j>=1&&!fg;j--) if(!rs[i][j]&&rs[i-1][j]) rs[i][j]=k,fg=1,lf[i]=j;
			for(int j=rg[i]+1;j<=y&&!fg;j++) if(!rs[i][j]&&rs[i+1][j]) rs[i][j]=k,fg=1,rg[i]=j;
		}if(!fg) return puts("-1"),0;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",rs[i][j],j==m?'\n':' ');
	return 0;
}