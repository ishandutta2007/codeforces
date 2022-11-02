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
int n,m,a[55][55],b[55][55],c[55][55];
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!a[i][j]) b[i][j]=b[i-1][j]=b[i][j-1]=b[i-1][j-1]=1;
	for(int i=1;i<n;i++) for(int j=1;j<m;j++) if(!b[i][j]) c[i][j]=c[i][j+1]=c[i+1][j]=c[i+1][j+1]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(c[i][j]^a[i][j]) return puts("-1"),0;
	int cnt=0;for(int i=1;i<n;i++) for(int j=1;j<m;j++) cnt+=!b[i][j];
	printf("%d\n",cnt);for(int i=1;i<n;i++) for(int j=1;j<m;j++) if(!b[i][j]) printf("%d %d\n",i,j);
}