#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-6;
typedef long long ll;
int n,m,k;
int dist[808][808];
vector<pair<int,pair<int,int> > >edge;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		edge.push_back(make_pair(z,make_pair(x,y)));
	}
	sort(edge.begin(),edge.end());
	map<int,int>use;
	for(int pos=0;pos<k&&pos<m;pos++){
		use[edge[pos].second.first];
		use[edge[pos].second.second];
	}
	int orz=0;
	for(auto &p:use)p.second=++orz;
	
	memset(dist,inf,sizeof dist);
	for(int i=0;i<k&&i<m;i++){
//		cerr<<use[edge[i].second.first]<<" "<<use[edge[i].second.second]<<" "<<edge[i].first<<endl;
		dist[use[edge[i].second.first]][use[edge[i].second.second]]=edge[i].first;
		dist[use[edge[i].second.second]][use[edge[i].second.first]]=edge[i].first;
	}
	for(int i=1;i<=802;i++)dist[i][i]=0;
	for(int k=1;k<=802;k++)for(int i=1;i<=802;i++)for(int j=1;j<=802;j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	vector<int>all;
	for(int i=1;i<=800;i++)for(int j=i+1;j<=800;j++)all.push_back(dist[i][j]);
	sort(all.begin(),all.end());
	cout<<all[k-1]<<endl;
	return 0;
}