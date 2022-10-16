#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
vector<pair<int,int> >g[222222];
int n,k,ans;
int ord[222222],col[222222];
void add(int &x){
	if(x==ans)x=1;
	else x++;
}
bool cmp(int x,int y){
	return g[x].size()>g[y].size();
}
void dfs(int x,int par,int c){
	int cnt=0;
	for(auto to:g[x])if(to.first!=par){
		add(cnt);
		if(cnt==c)add(cnt);col[to.second]=cnt;
		dfs(to.first,x,cnt);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(make_pair(b,i));
		g[b].push_back(make_pair(a,i));
	}
	for(int i=1;i<=n;i++)ord[i]=i;
	sort(ord+1,ord+n+1,cmp);ans=g[ord[k+1]].size();
	cout<<g[ord[k+1]].size()<<endl;
	dfs(ord[k+1],0,0);
	for(int i=1;i<n;i++)cout<<col[i]<<" ";cout<<endl;
	return 0;
}