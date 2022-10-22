#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10,mod=1e9+7;
int m,n,t_case;
ll ans[maxn],cnt[maxn],sum;
int main(){
	cnt[0]=cnt[1]=1;
	for(ri i=1;i<=200000;++i){
		ans[i]=(ans[i-1]+cnt[9])%mod;
		ri tmp=cnt[9];
		for(ri j=9;j;--j)cnt[j]=cnt[j-1];
		cnt[0]=tmp;
		cnt[1]=(cnt[1]+tmp)%mod;
	}
	scanf("%d",&t_case);
	while(t_case--){
		sum=0;
		scanf("%d%d",&n,&m);
		while(n){
			if(10-n%10<=m)
				sum=(sum+ans[m-(10-n%10)]+2)%mod;
			else sum=(sum+1)%mod;
			n/=10;
		}
		printf("%lld\n",sum);
	}
	return 0;
}