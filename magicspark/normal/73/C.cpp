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
string s;
int n,k;
int g[27][27];
int dp[105][105][27];
inline void upd(int &x,int y){
	if(x<y)x=y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(int i=0;i<105;i++)for(int j=0;j<105;j++)for(int k=0;k<26;k++)dp[i][j][k]=-inf;
	cin>>s>>k;
	cin>>n;
	for(char &c:s)c-='a';
	while(n--){
		char x,y;int c;
		cin>>x>>y>>c;
		g[x-'a'][y-'a']=c;
	}
	for(int i=0;i<26;i++)dp[0][i==s[0]?0:1][i]=0;
	for(int i=0;i<(int)s.size()-1;i++){
		for(int j=0;j<=k;j++){
			for(int pre=0;pre<26;pre++){
				for(int now=0;now<26;now++){
					if(j==k&&now!=s[i+1])continue; 
					upd(dp[i+1][j+(now!=s[i+1])][now],dp[i][j][pre]+g[pre][now]);
				}
			}
		}
	}
	int ans=-inf;
	for(int j=0;j<=k;j++){
		for(int now=0;now<26;now++){
			upd(ans,dp[(int)s.size()-1][j][now]);
		}
	}
	cout<<ans<<endl;
	return 0;
}