#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[2000005];
int Q,n,m,a[1000005],et,head[1000005],sz[1000005];priority_queue<long long>q;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	sz[x]=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		dfs(e[i].to,x),sz[x]+=sz[e[i].to],q.push(1ll*sz[e[i].to]*(n-sz[e[i].to]));
}
int main()
{
	for(read(Q);Q--;)
	{
		read(n),et=0,memset(head+1,0,sizeof(int)*n);while(!q.empty()) q.pop();
		for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
		dfs(1,0),read(m);int r=0;for(int i=1;i<=m;i++) read(a[i]);
		sort(a+1,a+m+1),a[0]=1;while(m>=n) a[n-1]=1ll*a[n-1]*a[m]%P,m--;
		while(!q.empty()) {long long x=q.top();q.pop(),r=(r+x%P*a[m]%P)%P,m--,m=max(m,0);}
		printf("%d\n",r);
	}
	return 0;
}