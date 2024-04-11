#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,m,c,ans,a[N],dst[N],q[N];bool vs[N];vector<int> e[N],pr[N];map<int,bool> tg[N]; 
void bfs(int S)
{
	q[0]=2;q[1]=1;vs[S]=1;q[++q[1]]=S;
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];
		for(int i=0,v;i<e[u].size();++i)
		{
			v=e[u][i];
			if(!vs[v]) vs[v]=1,dst[v]=dst[u]+1,q[++q[1]]=v;
			if(dst[u]+1==dst[v]) pr[v].push_back(u),tg[v][u]=1; 
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;++i) scanf("%d %d",&u,&v),e[v].push_back(u);
	scanf("%d",&c);for(int i=1;i<=c;++i) scanf("%d",&a[i]);bfs(a[c]);
	for(int i=1;i<c;++i) if(!tg[a[i]][a[i+1]]) ++ans;printf("%d ",ans);ans=0;
	for(int i=1;i<c;++i) if(pr[a[i]].size()>1 || (pr[a[i]].size()==1 && pr[a[i]][0]!=a[i+1])) ++ans;
	printf("%d\n",ans);return 0;
}