#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m;long long a[200005],s=0;
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,l=1;i<=m;i++)
	{
		long long x;read(x);
		while(l+1<=n&&s+a[l]<x) s+=a[l],l++;
		printf("%d %lld\n",l,x-s);
	}
	return 0;
}