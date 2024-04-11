#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,ans[N];
int cntE,hd[N];struct Edge {int v,nxt;}e[N<<1];
void addE(int u,int v) {e[++cntE]=(Edge) {v,hd[u]};hd[u]=cntE;}
bool dfs(int u,int f,int x)
{
	vector<int> ch;ch.clear();
	for(int i=hd[u],v;i;i=e[i].nxt) {v=e[i].v;if(v!=f) ch.push_back(i+1>>1);} 
	if(f && ch.size()>1) {ans[ch[0]]=ans[0]++;ans[ch[1]]=ans[0]++;ans[x]=ans[0]++;return 1;}
	for(int i=hd[u],v;i;i=e[i].nxt) {v=e[i].v;if(v!=f) {if(dfs(v,u,i+1>>1)) return 1;}}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i) ans[i]=-1,scanf("%d %d",&u,&v),addE(u,v),addE(v,u);
	dfs(1,0,0);for(int i=1;i<n;++i) {if(ans[i]==-1) ans[i]=ans[0]++;printf("%d\n",ans[i]);}
	return 0;
}