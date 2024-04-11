//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int u,v,w;bool operator<(node b) const {return w<b.w;}}a[300005];
int n,m,f[300005],g[300005];
int main()
{
	read(n),read(m);
	for(int i=1;i<=m;i++) read(a[i].u),read(a[i].v),read(a[i].w);
	sort(a+1,a+m+1);int mx=0;
	for(int i=1,j=1;i<=m;i=j=j+1)
	{
		while(j+1<=m&&a[j+1].w==a[i].w) ++j;
		for(int k=i;k<=j;k++) g[a[k].v]=max(g[a[k].v],f[a[k].u]+1);
		for(int k=i;k<=j;k++) f[a[k].v]=g[a[k].v];
	}
	for(int i=1;i<=n;i++) mx=max(mx,f[i]);
	return printf("%d\n",mx),0;
}