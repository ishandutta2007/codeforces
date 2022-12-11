#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>g[200001];
int a[200001],d[200001],d2[200001];
bool cmp(int u,int v){
	return d[u]<d[v];
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int>q;
	q.push(1);
	d[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
			if(!d[g[u][i]]){
				d[g[u][i]]=d[u]+1;
				q.push(g[u][i]);
			}
	}
	q.push(n);
	d2[n]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
			if(!d2[g[u][i]]){
				d2[g[u][i]]=d2[u]+1;
				q.push(g[u][i]);
			}
	}
	sort(a+1,a+k+1,cmp);
	int ans=-1;
	int mx=a[k];
	for(int i=k-1;i;i--){
		ans=max(ans,min(d[n]-d[1],d[a[i]]-d[1]+d2[mx]-d2[n]+1));
		if(d2[a[i]]>d2[mx])mx=a[i];
	}
	printf("%d\n",ans);
}