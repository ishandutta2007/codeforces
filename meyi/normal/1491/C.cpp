#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e4+10;
int n,t;
ll a,ans,f[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(f,0,sizeof f);
		ans=0;
		for(ri i=1;i<=n;++i){
			scanf("%lld",&a);
			for(ri j=min((ll)n,i+a);j>i+1;--j)++f[j];
			if(a<=f[i])f[i+1]+=f[i]-a+1;
			else ans+=a-f[i]-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}