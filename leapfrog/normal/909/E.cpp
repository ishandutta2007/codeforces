#include<bits/stdc++.h>
using namespace std;
struct node{int val,du;}a[100005];
int n,m,vis[100005],ans;vector<int>g[100005];queue<int>q[2];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].val),a[i].du=0;
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),g[y+1].push_back(x+1),a[x+1].du++;
	for(int i=1;i<=n;i++) if(!a[i].du) q[a[i].val].push(i);
	while(!q[0].empty()||!q[1].empty())
	{
		while(!q[0].empty())
		{
			int x=q[0].front();vis[x]=1,q[0].pop();
			for(int i=0;i<(int)g[x].size();i++) if(!vis[g[x][i]]) {a[g[x][i]].du--;if(!a[g[x][i]].du) q[a[g[x][i]].val].push(g[x][i]);}
		}
		if(!q[1].empty()) ans++;
		while(!q[1].empty())
		{
			int x=q[1].front();vis[x]=1,q[1].pop();
			for(int i=0;i<(int)g[x].size();i++) if(!vis[g[x][i]]) {a[g[x][i]].du--;if(!a[g[x][i]].du) q[a[g[x][i]].val].push(g[x][i]);}
		}
	}
	return printf("%d\n",ans),0;
}