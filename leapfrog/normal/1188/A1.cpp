//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
struct edge{int to,nxt;}e[200005];int n,m,et,head[100005],deg[100005];
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),deg[x]++,deg[y]++;
	for(int i=1;i<=n;i++) if(deg[i]==2) return puts("NO"),0;
	return puts("YES"),0;
}