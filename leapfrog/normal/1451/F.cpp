//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,m,xs[205];
int main()
{
	for(read(T);T--;)
	{
		read(n),read(m),memset(xs,0,sizeof(xs));int tag=0;
		for(int i=1,x;i<=n;i++) for(int j=1;j<=m;j++) read(x),xs[i+j]^=x;
		for(int i=1;i<=n+m;i++) if(xs[i]) {tag=1;break;}
		if(tag) puts("Ashish");else puts("Jeel");
	}
	return 0;
}