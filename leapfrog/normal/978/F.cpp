#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[400005];
int n,k,r[200005],et,head[200005],d[200005],ans[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline char cmp(int a,int b) {return r[a]<r[b];}
int main()
{
	read(n),read(k);
	for(int i=1;i<=n;i++) read(r[i]),d[i]=i;
	for(int i=1,x,y;i<=k;i++) read(x),read(y),adde(x,y),adde(y,x);
	sort(d+1,d+n+1,cmp),d[0]=0,r[0]=-1;
	for(int k=1,ls=0;k<=n;k++)
	{
		int tt=ls,x=d[k];if(r[d[k]]!=r[d[k-1]]) tt=ls=k;
		for(int i=head[x];i;i=e[i].nxt) if(r[e[i].to]<r[x]) tt--;
		ans[x]=tt-1;
	}
	for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}