#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,a[N];ll ans,s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		ll s0=1ll*(n-1)*a[1],s1=1ll*(n-1)*a[n];
		for(int i=2;i<=n;i++)s0+=a[i];
		for(int i=1;i<n;i++)s1+=a[i];
		if(s0>0||s1<0){printf("INF\n");continue;}
		ans=-1e18;
		for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
		for(int i=1;i<=n;i++)ans=max(ans,s[i]*(a[n]-a[i])+(s[n]-s[i])*(a[1]-a[i])-1ll*i*a[i]*a[n]-1ll*(n-i)*a[i]*a[1]-1ll*a[1]*a[n]+1ll*(a[1]+a[n])*a[i]);
		printf("%lld\n",ans);
	}
	return 0;
}