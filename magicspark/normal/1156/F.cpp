#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=998244353;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int a[5005],cnt[5005],inv[5005];
int dp[5005][5005],sum[5005][5005];
inline void add(int &x,int y){(x+=y)%=mod;}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;cnt[0]=1;for(int i=0;i<=5000;i++)inv[i]=modpow(i,mod-2);
	for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;
	for(int i=n;i>=0;i--){
		for(int j=n;j>=0;j--){
			add(sum[i][j],sum[i+1][j]);
			if(cnt[i]==0||j==n)continue;
			add(dp[i][j],(ll)sum[i+1][j+1]*inv[n-j]%mod);
			add(dp[i][j],(ll)(cnt[i]-1)*inv[n-j]%mod);
			add(sum[i][j],(ll)cnt[i]*dp[i][j]%mod);
		}
	}
	cout<<dp[0][0]<<endl;
	return 0;
}