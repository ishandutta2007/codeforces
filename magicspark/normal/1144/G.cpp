#include<bits/stdc++.h>
#define dec sjcakioi
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int dp[222222][2],p[222222][2];
int a[222222],ans[222222],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;++i)dp[i][0]=-inf,dp[i][1]=inf;
    dp[1][0]=inf;
    dp[1][1]=-inf;
    for(int i=2;i<=n;i++) {
        if(a[i]>a[i-1]&&dp[i][0]<dp[i-1][0]) {
            dp[i][0]=dp[i-1][0];
            p[i][0]=0;
        }
        if(a[i]<dp[i-1][0] && dp[i][1]>a[i-1]) {
            dp[i][1]=a[i-1];
            p[i][1]=0;
        }
        if(a[i]>dp[i-1][1] && dp[i][0]<a[i-1]) {
            dp[i][0]=a[i-1];
            p[i][0]=1;
        }
        if(a[i]<a[i-1] && dp[i][1]>dp[i-1][1]) {
            dp[i][1]=dp[i-1][1];
            p[i][1]=1;
        }
    }
	if(dp[n][0]==-inf&&dp[n][1]==inf)return puts("NO")&0;
	puts("YES");
	int T=(dp[n][0]==-inf)?1:0;
    for(int i=n;i>=1;i--){
        ans[i]=T;
        T=p[i][T];
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}