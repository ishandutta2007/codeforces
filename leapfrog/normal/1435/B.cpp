//
//
#include<bits/stdc++.h>
using namespace std;const int X=303;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,m,a[1005][1005],b[1005][1005],mp[1000005];
int main()
{
	for(read(T);T--;)
	{
		read(n),read(m);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(b[i][j]),mp[b[i][j]]=i;
		for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) read(a[i][j]);
		for(int i=1;i<=n;i++)
		{
			int zkak=mp[a[1][i]];
			for(int j=1;j<=m;j++) printf("%d%c",b[zkak][j],j==m?'\n':' ');
		}
	}
	return 0;
}