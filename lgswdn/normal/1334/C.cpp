#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+9;
int T,n,a[N],b[N],c[N];
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n); int sum=0,ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]),c[i]=max(0ll,a[i]-b[i-1]);
		c[1]=max(0ll,a[1]-b[n]); for(int i=1;i<=n;i++) sum+=c[i];
		for(int i=1;i<=n;i++) ans=min(ans,sum-c[i]+a[i]);
		printf("%lld\n",ans); 
	}
	return 0;
}