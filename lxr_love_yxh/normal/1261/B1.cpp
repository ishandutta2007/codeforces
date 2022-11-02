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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
int a[105],ans[105];
int dp[105][105];
vector<int>seq[105];
void init(){
	memset(dp,-1,sizeof dp);
	for(int i=n;i>=1;i--){
		dp[i][1]=a[i];
		for(int j=2;j<=100;j++){
			for(int p=i+1;p<=n;p++){
				if(dp[p][j-1]!=-1){
					dp[i][j]=max(dp[i][j],dp[p][j-1]+a[i]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans[i]=max(ans[i],dp[j][i]); 
		}
	}
	for(int l=1;l<=n;l++){
		int rest=l,now=0,res=ans[l];
		while(rest){
			pair<int,int>best=make_pair(inf,inf);
			for(int j=now+1;j<=n;j++){
				if(dp[j][rest]==res){
					best=min(best,make_pair(a[j],j));
				}
			}
			seq[l].push_back(best.first);res-=best.first;now=best.second;rest--;
		}
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	init();
	cin>>m;
	while(m--){
		int k,p;cin>>k>>p;p--;
		cout<<seq[k][p]<<endl;
	}
	return 0;
}