//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
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
int n,sum[200005];
int dp1[200005],dp2[200005];
vector<int>g[200005];
void get_sum(int x,int par=0){
	for(auto to:g[x])if(to!=par){
		get_sum(to,x);
		sum[x]+=sum[to];
	}
	sum[x]++;
}
void dfs(int x,int par=0){
	if(g[x].size()==1&&par!=0){
		dp2[x]=1;dp1[x]=sum[1];
		return;
	}
	for(auto to:g[x]){
		if(to!=par){
			dfs(to,x);
		}
	}
	dp2[x]=sum[x];
	for(auto to:g[x]){
		if(to!=par){
			dp2[x]+=dp2[to];
		}
	}
	dp1[x]=sum[1]-sum[x]+dp2[x];
	int sumdp2=0;
	for(auto to:g[x]){
		if(to!=par){
			sumdp2+=dp2[to];
		}
	}
	for(auto to:g[x]){
		if(to!=par){
			dp1[x]=max(dp1[x],dp1[to]-dp2[to]+sumdp2+sum[1]-sum[to]);
		}
	}
//	cerr<<x<<" "<<dp1[x]<<" "<<dp2[x]<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	get_sum(1);
	dfs(1);
	cout<<dp1[1]<<endl;
	return 0;
}