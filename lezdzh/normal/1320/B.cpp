#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

vector<int>g[200001],g2[200001];
int c[200001],d[200001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[v].push_back(u);
		g2[u].push_back(v);
	}
	scanf("%d",&c[0]);
	for(int i=1;i<=c[0];i++)
		scanf("%d",&c[i]);
	queue<int>q;
	q.push(c[c[0]]);
	d[c[c[0]]]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
			if(!d[g[u][i]]){
				d[g[u][i]]=d[u]+1;
				q.push(g[u][i]);
			}
	}
	int l=0,r=0;
	for(int i=1;i<c[0];i++){
		int z=0;
		for(int j=0;j<g2[c[i]].size();j++)
			if(d[g2[c[i]][j]]==d[c[i]]-1)z++;
		if(d[c[i+1]]!=d[c[i]]-1)l++,r++;
		else if(z!=1)r++;
	}
	printf("%d %d\n",l,r);
}