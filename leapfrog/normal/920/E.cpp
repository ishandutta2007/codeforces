#include<bits/stdc++.h>
using namespace std;
int n,m,tot=0,ans[200005];set<int>nv;map<int,int>e[200005];
inline int bfs(int x)
{
	queue<int>q;q.push(x);int sz=0;
	while(!q.empty())
	{
		int x=q.front();q.pop(),sz++;
		for(set<int>::iterator i=nv.begin(),r;i!=nv.end();) if(!e[x][*i]) q.push(*i),r=i,i++,nv.erase(r);else i++;
	}
	return sz;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),e[x][y]=1,e[y][x]=1;
	for(int i=1;i<=n;i++) nv.insert(i);
	for(int x;!nv.empty();) x=*nv.begin(),nv.erase(x),ans[++tot]=bfs(x);
	printf("%d\n",tot),sort(ans+1,ans+tot+1);
	for(int i=1;i<=tot;i++) printf("%d%c",ans[i],i==tot?'\n':' ');
	return 0;
}