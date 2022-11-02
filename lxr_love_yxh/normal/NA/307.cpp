/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n;
int h[200005],t[200005],in[200005],out[200005],vis[200005]; 
vector<int>g[200005];
int dp[200005][2];
bool cmp(pair<int,int>a,pair<int,int>b){
	return a.first-a.second<b.first-b.second;
}
void dfs(int x,bool rt=0){
	//0 up,1 down
	vis[x]=1;
	vector<pair<int,int> >vec;
	for(auto to:g[x])if(!vis[to]){
		dfs(to);vec.push_back(make_pair(dp[to][0],dp[to][1]));
	}
	sort(vec.begin(),vec.end(),cmp);
	//First part up,Second part down
	vector<int>pref0(vec.size()+1,0),pref1(vec.size()+1,0);
	for(int i=1;i<=vec.size();i++){
		pref0[i]=pref0[i-1]+vec[i-1].first;
		pref1[i]=pref1[i-1]+vec[i-1].second;
	}
	for(int i=0;i<=vec.size();i++){
		int add_in=i,add_out=vec.size()-i;
		int val=pref0[i]+pref1[vec.size()]-pref1[i];
		dp[x][0]=min(dp[x][0],val+max(add_in+in[x],add_out+out[x]+1-rt)*t[x]);
		dp[x][1]=min(dp[x][1],val+max(add_in+in[x]+1-rt,add_out+out[x])*t[x]);
	}
}
signed main(){
	memset(dp,inf,sizeof dp);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>t[i];
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		if(h[x]==h[y]){
			g[x].push_back(y);
			g[y].push_back(x);
		}else{
			if(h[x]<h[y])out[x]++,in[y]++;
			else in[x]++,out[y]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
//		cerr<<i<<" "<<in[i]<<" "<<out[i]<<endl;
		if(!g[i].size()){
			ans+=max(in[i],out[i])*t[i];
		}else if(!vis[i]){
			dfs(i,1);ans+=min(dp[i][0],dp[i][1]);
//			cerr<<dp[i][0]<<" "<<dp[i][1]<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}