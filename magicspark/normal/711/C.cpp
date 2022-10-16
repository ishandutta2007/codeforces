#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m,k;
int dp[105][105][105];
int p[105][105],c[105];
int upd(int &x,int y){
	x=min(x,y);
}
signed main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>p[i][j];
	memset(dp,inf,sizeof dp);
	dp[0][0][0]=0;
	for(int i=0;i<n;i++){
		for(int b=0;b<=k;b++){
			for(int pre=0;pre<=m;pre++){
				if(c[i+1]==0){
					for(int nxt=1;nxt<=m;nxt++){
						upd(dp[i+1][b+(nxt!=pre)][nxt],dp[i][b][pre]+p[i+1][nxt]);
					}
				}else{
					upd(dp[i+1][b+(c[i+1]!=pre)][c[i+1]],dp[i][b][pre]);
				}
			}
		}
	}
	int ans=*min_element(dp[n][k],dp[n][k+1]);
	if(ans==inf){
		cout<<-1<<endl;
	}else{
		cout<<ans<<endl;
	}
	return 0;
}