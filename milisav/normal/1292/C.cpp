#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > a[10000];
pair<int,int> edge[10000];
pair<int,int> dep[10000];
pair<int,int> bd[10000];
pair<int,int> bv[10000];
bool vis[10000];
bool ex[10000];
int val[10000];
vector<pair<int,int> > sed;
vector<pair<pair<int,int>,pair<int,int> > > dist[10000];
long long dp[3100][3100];
int n;
int dfs(int u) {
	vis[u]=true;
	int v=0;
	int c=1;
	for(int j=0;j<a[u].size();j++) {
		v=a[u][j].first;
		if(!vis[v]) c+=dfs(v);
	}
	return c;
}
void find(int i) {
	int u=edge[i].first;
	int v=edge[i].second;
	vis[u]=vis[v]=true;
	int a=dfs(u);
	int b=dfs(v);
	for(int i=0;i<=n;i++) vis[i]=false;
	dep[i]={a,b};
}
void dfs_find(int u,int bg,int be,int ee,int d=0) {
	if(d!=0) {
		dist[d].push_back({{bg,u},{be,ee}});
	}
	vis[u]=true;
	int v;
	for(int i=0;i<a[u].size();i++) {
		v=a[u][i].first;
		if(!vis[v]) {
			if(u==bg) dfs_find(v,bg,a[u][i].second,a[u][i].second,d+1);
			else dfs_find(v,bg,be,a[u][i].second,d+1);
		}
	}
}
int main() {
	int u,v;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++) {
		scanf("%d %d",&u,&v);
		a[u].push_back({v,i});
		a[v].push_back({u,i});
		edge[i]={u,v};
	}
	for(int i=0;i<n-1;i++) find(i);
	long long s=0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=n;j++) vis[j]=false;
		dfs_find(i,i,-1,-1,0);
	}
	for(int i=1;i<=n;i++) {
		for(int j=0;j<dist[i].size();j++) {
			u=dist[i][j].first.first;
			v=dist[i][j].first.second;
			int eu=dist[i][j].second.first;
			int ev=dist[i][j].second.second;
			long long pu,pv,qu,qv;
			if(edge[eu].first==u) pu=dep[eu].first;
			else pu=dep[eu].second;
			if(edge[ev].first==v) pv=dep[ev].first;
			else pv=dep[ev].second;
			int wu,wv;
			if(edge[eu].first==u) wu=edge[eu].second;
			else wu=edge[eu].first;
			if(edge[ev].first==v) wv=edge[ev].second;
			else wv=edge[ev].first;
			//cout<<u<<" "<<v<<" "<<eu<<" "<<ev<<" "<<wu<<" "<<wv<<" "<<pu<<" "<<pv<<" "<<i<<endl;
			dp[u][v]=max(dp[u][v],max(dp[wu][v],dp[u][wv])+pu*pv);
			dp[v][u]=max(dp[v][u],dp[u][v]);
			//cout<<dp[u][v]<<endl;
			s=max(s,dp[u][v]);
		}
	}
	printf("%lld",s);
	return 0;
}