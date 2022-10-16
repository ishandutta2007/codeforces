#pragma optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=998244353;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,k,l;
gp_hash_table<int,int>Inv;
int dp[2][2005],c[2005][2005],b[2004005],pre[2004005],suf[2004005],sz;
void calc(){
	int tmp=1;
	pre[0]=1;suf[sz+1]=1;
	for(int i=1;i<=sz;i++)pre[i]=pre[i-1]*b[i]%mod;
	for(int i=sz;i>=1;i--)suf[i]=suf[i+1]*b[i]%mod;
    tmp=pre[sz];
	int inv=modpow(tmp,mod-2);
	for(int i=1;i<=sz;i++)Inv[b[i]]=(inv*pre[i-1]%mod*suf[i+1]%mod);;
}
inline int inv(int x){x%=mod;return x?Inv[x]:0;}
inline void add(int &x,int y){x=(x+y)%mod;}
signed main(){
	c[0][0]=1;dp[0][0]=1;
	cin>>n>>k>>l;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			if(i||j)c[i][j]=((!i?0:c[i-1][j]*(i-j))+(!j?0:c[i][j-1])),c[i][j]%=mod;
//	while(1){int x,y;cin>>x>>y;cout<<c[x][y]<<endl;}
	int ans=0;
	for(int i=0;i<=n+n;i++){
		for(int j=0;j<=n&&j<=i&&j<=(n+n-i);j++){
			int right=(i-j)/2,left=(i+j)/2;
			left=n-left;right=n-right;
			int Left=!left?0ll:c[right][left-1],Right=(left==right)?0ll:c[right-1][left]*j;
			Left%=mod;Right%=mod;
			if(Left+Right && ((i&1)==(j&1)))b[++sz]=(Left+Right)%mod;
		}
	}
	calc();
	for(int i=0;i<=n+n;i++){
		for(int j=0;j<=n&&j<=i&&j<=(n+n-i);j++){
			if(!dp[i&1][j])continue;
			int right=(i-j)/2,left=(i+j)/2;
			left=n-left;right=n-right;
			int Left=!left?0ll:c[right][left-1],Right=(left==right)?0ll:c[right-1][left]*j;
			Left%=mod;Right%=mod;
			add(dp[(i+1)&1][j+1],dp[i&1][j]*(Left)%mod*inv(Left+Right)%mod);
			if(j)add(dp[(i+1)&1][j-1],dp[i&1][j]*(Right)%mod*inv(Left+Right)%mod);
			if(j>=k)ans+=dp[i&1][j],ans%=mod;
		}memset(dp[i&1],0,sizeof dp[i&1]);
	}
	ans=ans*l%mod*modpow(n+n+1,mod-2)%mod;
	cout<<ans<<endl;
	return 0;
}