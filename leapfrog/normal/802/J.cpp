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
struct edge{int to,w,nxt;}e[200005];int n,et,head[100005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline int dfs(int x,int fa)
{
	int mx=0;for(int i=head[x];i;i=e[i].nxt)
		if(e[i].to!=fa) mx=max(mx,e[i].w+dfs(e[i].to,x));
	return mx;
}
int main()
{
	read(n);for(int i=1,x,y,w;i<n;i++)
		read(x),read(y),x++,y++,read(w),adde(x,y,w),adde(y,x,w);
	return printf("%d\n",dfs(1,0)),0;
}