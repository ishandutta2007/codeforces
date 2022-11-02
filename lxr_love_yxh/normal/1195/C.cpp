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
int n;
int a[200005][2];
int dp[200005][2];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][0];
	for(int i=1;i<=n;i++)cin>>a[i][1];
	dp[1][0]=a[1][0];dp[1][1]=a[1][1];
	for(int i=2;i<=n;i++){
		for(int j=0;j<2;j++){
			dp[i][j]=max(dp[i-1][0],dp[i-1][1]);
			dp[i][j]=max(dp[i][j],dp[i-1][1^j]+a[i][j]);
		}
	}
	cout<<max(dp[n][0],dp[n][1])<<endl;
	return 0;
}