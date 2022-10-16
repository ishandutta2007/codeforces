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
int n,m,k;
pair<int,int>p[100005];
vector<int>l[200005],r[200005];
map<int,int>mp;
int to[200005],hv[200005];
int inv[200005];
int dp[200005][256];
signed main(){
	cin>>n>>m>>k;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].first>>p[i].second;p[i].second++;mx+=p[i].second-p[i].first; 
		mp[p[i].first];mp[p[i].second];
	}
	int tot=0;for(auto&p:mp)p.second=++tot,inv[tot]=p.first;
	for(int i=1;i<=n;i++){
		p[i].first=mp[p[i].first];
		p[i].second=mp[p[i].second];
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		l[p[i].first].push_back(i);
		r[p[i].second].push_back(i);
	}
	memset(dp,0xf7,sizeof dp);
	memset(hv,-1,sizeof hv);
	dp[0][0]=0;inv[tot+1]=m+1;
	for(int i=1;i<=tot;i++){
		for(auto x:r[i]){
			for(int j=0;j<(1<<k);j++)if(j&(1<<to[x])){
				dp[i-1][j^(1<<to[x])]=max(dp[i-1][j^(1<<to[x])],dp[i-1][j]);
				dp[i-1][j]=-inf;
			}
			hv[to[x]]=-1;
		}
		for(int j=0;j<(1<<k);j++){
			dp[i][j]=dp[i-1][j]+(inv[i+1]-inv[i])*(__builtin_popcount(j)%2);
		}
		for(auto x:l[i]){
			for(int t=0;t<k;t++)if(hv[t]){
				to[x]=t;break;
			}
			hv[to[x]]=0;
			for(int j=0;j<(1<<k);j++)if(j&(1<<to[x])){
				dp[i][j]=max(dp[i][j],dp[i][j^(1<<to[x])]+(inv[i+1]-inv[i])*(__builtin_popcount(j)%2?1:-1));
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<k);i++)ans=max(ans,dp[tot][i]);
	cout<<ans<<endl;
	return 0;
}