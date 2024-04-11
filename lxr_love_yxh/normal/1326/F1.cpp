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
int n;
string s[14];
vector<int>dp[1<<14][14];
signed main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=1;i<(1<<n);i++)for(int j=0;j<n;j++)dp[i][j].resize((1<<__builtin_popcount(i)-1),0);
	for(int i=0;i<n;i++)dp[1<<i][i][0]=1;
	for(int i=1;i<(1<<n);i++){
		int cnt=__builtin_popcount(i)-1;
		for(int now=0;now<n;now++)if(i&(1<<now))
		for(int j=0;j<(1<<cnt);j++){
			for(int nxt=0;nxt<n;nxt++)if(~i&(1<<nxt)){
				dp[i|(1<<nxt)][nxt][j*2+(s[now][nxt]=='1')]+=dp[i][now][j];
			}
		}
	}
	vector<int>ans(1<<n,0);
	for(int i=0;i<(1<<n-1);i++){
		for(int j=0;j<n;j++)ans[i]+=dp[(1<<n)-1][j][i];
	}
	for(int i=0;i<(1<<n-1);i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}