#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,k,a[N];ll ans,s[N];
void solve(){
	scanf("%d%d",&n,&k),ans=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==1){printf("%d\n",a[1]+k-1);return;}
	if(k<=n){
		for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
		for(int i=k;i<=n;i++)ans=max(ans,s[i]-s[i-k]);
		printf("%lld\n",ans+1ll*k*(k-1)/2);
		return;
	}
	for(int i=1;i<=n;i++)ans+=a[i];ans+=1ll*n*k-1ll*n*(n+1)/2;
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}