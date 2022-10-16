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
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int dp[100005];
int n,m,cnt[100005];
int par[100005];
int find(int x){
	if(x==par[x])return x;
	return par[x]=find(par[x]);
}
void unite(int x,int y){
	par[find(x)]=find(y);
}
bool lucky(int x){
	while(x){
		if(x%10!=4&&x%10!=7)return false;
		x/=10;
	}
	return true;
}
map<int,int>hop;
const int magic=230;
int main(){
	memset(dp,inf,sizeof dp);
	dp[0]=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)par[i]=i;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		unite(x,y);
	}
	for(int i=1;i<=n;i++)hop[find(i)]++;
	for(auto p:hop){
		if(p.second<=magic){
			cnt[p.second]++;
		}else{
			int v=p.second;
			for(int i=n-v;i>=0;i--)dp[i+v]=min(dp[i+v],dp[i]+1);
		}
	}
	for(int i=1;i<=magic;i++){
		vector<int>azis;
		int now=cnt[i];
		for(int j=1;now>=j;j*=2){
			azis.push_back(j);
			now-=j;
		}
		if(now)azis.push_back(now);
		for(auto x:azis){
			for(int j=n-i*x;j>=0;j--){
				dp[j+i*x]=min(dp[j+i*x],dp[j]+x);
			}
		}
	}
	int ans=inf;
	for(int i=1;i<=n;i++)if(lucky(i))ans=min(ans,dp[i]);
	cout<<(ans==inf?-1:ans-1)<<endl;
	return 0;
}