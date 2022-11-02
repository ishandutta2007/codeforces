#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int sum[5555];
vector<int>g[5555];
set<pair<int,int> >ans;
void dfs(int x,int par=0){
	sum[x]=1;
	for(auto to:g[x])if(to!=par)dfs(to,x);
	for(auto to:g[x])if(to!=par)sum[x]+=sum[to];
	vector<bool>ok(5555,false);
	ok[0]=true;
	for(auto to:g[x])if(to!=par){
		for(int i=5005;i>=0;i--)if(ok[i]&&i+sum[to]<=5005)ok[i+sum[to]]=true;
	}
	for(int i=1;i<=5005;i++)if(ok[i]&&n-i-1>=1)ans.insert(make_pair(i,n-i-1)),ans.insert(make_pair(n-i-1,i));
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	cout<<ans.size()<<endl;
	for(auto p:ans)cout<<p.first<<" "<<p.second<<endl;
	return 0;
}