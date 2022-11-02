#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[1000005],t[1000005],l,r;
int main()
{
	read(n),l=1,r=n;for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) if(i&1) t[i]=a[r--];else t[i]=a[l++];
	printf("%d\n",(n-1)>>1);for(int i=1;i<=n;i++) printf("%d%c",t[i],i==n?'\n':' ');
	return 0;
}