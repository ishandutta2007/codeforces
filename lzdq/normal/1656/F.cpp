#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN];
ll ans;
ll sum[MAXN];
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		ll s=0;
		for(int i=1; i<n; i++)
			s+=a[i]+a[n];
		if(s<0){
			puts("INF");
			continue;
		}
		s=0;
		for(int i=2; i<=n; i++)
			s+=a[1]+a[i];
		if(s>0){
			puts("INF");
			continue;
		}
		for(int i=1; i<=n; i++)
			sum[i]=sum[i-1]+a[i];
		ans=min(1ll*a[1]*a[1],1ll*a[n]*a[n])*(1-n);
		for(int i=2; i<n; i++){
			//printf("ans %lld\n",ans);
			ll s1=sum[i],s2=sum[n]-sum[i],t=-a[i];
			ans=max(ans,(a[1]+t)*(s2+(n-i)*t)+(a[n]+t)*(s1+i*t)-(a[1]+t)*(a[n]+t)-(n-1)*t*t);
		}
		printf("%lld\n",ans);
	}
	return 0;
}