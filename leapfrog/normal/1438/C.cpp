//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,m,a[105][105];
int main()
{
	for(read(T);T--;)
	{
		read(n),read(m);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(((i+j)&1)^(a[i][j]&1)) a[i][j]++;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",a[i][j],j==m?'\n':' ');
	}
	return 0;
}