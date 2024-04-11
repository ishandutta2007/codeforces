//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,m,a[105][105],b[105],c[105];
inline int qry(int x)
{//
	b[1]=x;for(int j=1;j<=m;j++) if(a[1][j]<b[1]) return 1e9;else c[j]=a[1][j]-b[1];
	for(int i=1;i<=n;i++) if(a[i][1]<c[1]) return 1e9;else b[i]=a[i][1]-c[1];
	for(int i=2;i<=n;i++) for(int j=2;j<=m;j++) if(b[i]+c[j]!=a[i][j]) return 1e9;
	int sm=0;for(int i=1;i<=n;i++) sm+=b[i];
	for(int i=1;i<=m;i++) sm+=c[i];
	return sm;
}
inline void paint(int i)
{
	qry(i);for(int i=1;i<=n;i++) for(int j=1;j<=b[i];j++) printf("row %d\n",i);
	for(int i=1;i<=m;i++) for(int j=1;j<=c[i];j++) printf("col %d\n",i);
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
	int mx=1e9,wh=-1;for(int i=0,tt;i<=a[1][1];i++) {tt=qry(i);if(tt<=mx) mx=tt,wh=i;}
	if(mx>=1000000000) return puts("-1"),0;else return printf("%d\n",mx),paint(wh),0;
}