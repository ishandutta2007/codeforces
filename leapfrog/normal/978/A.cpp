#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[55],t[1005],v[55];
int main()
{
	read(n);int tot=0;for(int i=1;i<=n;i++) read(a[i]);
	for(int i=n;i>=1;i--) if(!t[a[i]]) v[i]=1,t[a[i]]=1;
	for(int i=1;i<=n;i++) if(v[i]) tot++;
	printf("%d\n",tot);
	for(int i=1;i<=n;i++) if(v[i]) printf("%d ",a[i]);
	return putchar('\n'),0;
}