#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
int n,t;
ll a[maxn],ans,b[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%lld%lld",a+i,b+i);
		ans=max(a[1]-b[n],0ll);
		a[1]=min(a[1],b[n]);
		for(ri i=2;i<=n;++i)ans+=max(a[i]-b[i-1],0ll),a[i]=min(a[i],b[i-1]);
		sort(a+1,a+n+1);
		printf("%lld\n",ans+a[1]);
	}
	return 0;
}