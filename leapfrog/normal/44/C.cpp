//
//
#include<bits/stdc++.h>
using namespace std;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,a[105];
int main()
{
	read(n),read(m);int l,r;
	for(int i=1;i<=m;i++) {read(l),read(r);for(int j=l;j<=r;j++) a[j]++;}
	for(int i=1;i<=n;i++) if(a[i]!=1) return printf("%d %d\n",i,a[i]),0;
	return puts("OK"),0;
}