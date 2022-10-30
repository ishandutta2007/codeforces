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
int T,n,a[100005];long long m;
int main()
{
	for(read(T);T--;)
	{
		read(n),read(m);
		for(int i=1,x;i<=n;i++) read(x),m-=x;
		if(!m) puts("YES");else puts("NO");
	}
}