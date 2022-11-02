//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,a[100005],bt[35];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) for(int j=0;j<31;j++) bt[j]+=(a[i]>>j)&1;
	int mx=0,mw=1;for(int i=1;i<=n;i++)
	{
		int res=0;
		for(int j=0;j<31;j++) if(((a[i]>>j)&1)&&bt[j]==1) res+=1<<j;
		if(res>=mx) mx=res,mw=i;
	}
	printf("%d ",a[mw]);for(int i=1;i<=n;i++) if(i^mw) printf("%d ",a[i]);
	return putchar('\n'),0;
}