#include<cstdio>
#include<vector>
using namespace std;

vector<int>g[2001];
int sz[2001],a[2001],c[2001];
void dfs0(int u){
	sz[u]=1;
	for(int i=0;i<g[u].size();i++){
		dfs0(g[u][i]);
		sz[u]+=sz[g[u][i]];
	}
}
void sp(vector<int>&p,vector<int>&q,int z){
	p.clear();
	for(int i=0;i<z;i++)
		p.push_back(q[i]);
	for(int i=z;i<q.size();i++)
		q[i-z]=q[i];
	for(int i=0;i<z;i++)
		q.pop_back();
}
bool dfs(int u,vector<int>&w){
	if(c[u]>=w.size())return 0;
	a[u]=w[c[u]];
	for(int i=c[u]+1;i<w.size();i++)
		w[i-1]=w[i];
	w.pop_back();
	for(int i=0;i<g[u].size();i++){
		vector<int>ww;
		sp(ww,w,sz[g[u][i]]);
		if(!dfs(g[u][i],ww))return 0;
	}
	return 1;
}
int main(){
	int n,o;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int f;
		scanf("%d%d",&f,&c[i]);
		if(f)g[f].push_back(i);
		else o=i;
	}
	dfs0(o);
	vector<int>w;
	for(int i=1;i<=n;i++)
		w.push_back(i);
	if(!dfs(o,w)){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)
		printf("%d%c",a[i],i==n?'\n':' ');
}