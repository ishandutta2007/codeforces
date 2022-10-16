#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
typedef long long ll;
int n,nn,sz[133333],p;
vector<int>g[133333],V;
void dfs_sz(int x,int par){
	sz[x]=1;
	for(int to:g[x]){
		if(to!=par){
			dfs_sz(to,x);
			sz[x]+=sz[to];
		}
	}
	if(sz[x]==n/2||sz[x]==n/2+1){
		V.push_back(x);
		if(~par)V.push_back(par);
	}
}
int dp[133333];
int dfs(int x,int par){
	if(g[x].size()-(par!=-1)==0){
		dp[x]=1;return dp[x];
	}
	vector<int>v;
	for(int to:g[x]){
		if(to!=par){
			dfs(to,x);
			v.push_back(dp[to]);
		}
	}
	sort(v.begin(),v.end());
	if(v.size()==1){
		if(v[0]==1){
			dp[x]=-2;p=x;
		}else{
			dp[x]=inf;
		}
	}else if(v.size()==2){
		if(v[1]<0){
			dp[x]=inf;
		}else if(v[0]<0){
			if(v[0]+v[1]==0)dp[x]=v[0]-1;
			else dp[x]=inf;
		}else{
			if(v[0]==v[1]){
				dp[x]=v[0]+1;
			}
		}
	}else if(v.size()==3){
		if(v[0]==v[1]&&v[2]==v[1]+1){
			dp[x]=-v[2]-1;p=x;
		}else{
			dp[x]=inf;
		}
	}
	return dp[x];
}
int main(){
	cin>>nn;n=(1<<nn)-2;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs_sz(1,-1);
	set<int>ans;
	for(int x:V){
		p=0;dfs(x,-1);if(dp[x]==-nn&&p)ans.insert(p);
	}
	cout<<ans.size()<<endl;
	for(int x:ans){
		cout<<x<<" ";
	}
	return 0;
}