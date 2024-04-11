#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=210;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
ll ans,k,sum;
int a[maxn],mx,n;
int main(){
	scanf("%d%lld",&n,&k);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i),ckmax(mx,a[i]);
		sum+=a[i];
	}
	if(k>=1ll*mx*n-sum)return printf("%lld",mx+(k-(1ll*mx*n-sum))/n),0;
	for(ri i=1;i<=mx;){
		ri nxt=0x3f3f3f3f;
		ll tmp=0;
		for(ri j=1;j<=n;++j)
			if(a[j]>i){
				ckmin(nxt,(a[j]-1)/((a[j]-1)/i));
				tmp+=(a[j]-1)/i;
			}
		if((n+tmp)*i<=k+sum)ckmax(ans,(k+sum)/(n+tmp));
		i=nxt+1;
	}
	printf("%lld",ans);
	return 0;
}