#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[200005];
int t,n,et,head[100005],s[100005],rt,mn;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa=0)
{
	s[x]=1;int mx=0;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x),s[x]+=s[e[i].to],mx=max(mx,s[e[i].to]);
	mx=max(mx,n-s[x]);if(mn>mx) mn=mx,rt=x;
}
int main()
{
	for(scanf("%d",&t),s[0]=0;t--;)
	{
		scanf("%d",&n),et=0,mn=1e9;for(int i=1;i<=n;i++) head[i]=0;
		int x,y;for(int i=1;i<n;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
		dfs(1),dfs(rt);if(rt==1||n==2) {printf("%d %d\n%d %d\n",x,y,x,y);continue;}
		int w=0;for(int i=head[rt];i;i=e[i].nxt) if(s[e[i].to]>s[w]) w=e[i].to;
		int z=0;for(int i=head[w];i;i=e[i].nxt) if(e[i].to!=rt&&s[e[i].to]>s[z]) z=e[i].to;
		if(z==0) printf("%d %d\n%d %d\n",x,y,x,y);else printf("%d %d\n%d %d\n",w,z,rt,z);
	}
}