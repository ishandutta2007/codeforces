#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1010,mod=1e9+7;
int t_case;
ll ans,f[maxn],k,n;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld%lld",&n,&k);
		if(k==1)ans=1;
		if(k>1){
			ans=n+1;
			memset(f,0,sizeof f);
			for(ri i=1;i<n;++i)f[i]=1;
			for(ri i=2;i<k;++i){
				if(i&1)for(ri j=1;j<n;++j)f[j]=(f[j]+f[j-1])%mod,ans=(ans+f[j])%mod;
				else for(ri j=n-1;j;--j)f[j]=(f[j]+f[j+1])%mod,ans=(ans+f[j])%mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}