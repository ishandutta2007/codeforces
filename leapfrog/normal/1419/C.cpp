#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int Q,n,x,a[1000005];
int main()
{
	for(read(Q);Q--;)
	{
		read(n),read(x);int f1=0,s=0;
		for(int i=1;i<=n;i++) read(a[i]),s+=a[i];
		for(int i=1;i<=n;i++) f1+=(a[i]==x);
		if(f1==n) puts("0");else if(f1>=1) puts("1");else if(s==x*n) puts("1");else puts("2");
	}
	return 0;
}