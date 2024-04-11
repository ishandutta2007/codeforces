#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
typedef long long ll;
int T,n,a,b,x[N];ll ans,s[N];
void solve(){
	scanf("%d%d%d",&n,&a,&b),ans=5e18;
	for(int i=1;i<=n;i++)scanf("%d",&x[i]),s[i]=s[i-1]+x[i];
	for(int i=0;i<=n;i++)ans=min(ans,1ll*(a+b)*x[i]+1ll*b*(s[n]-s[i]-1ll*(n-i)*x[i]));
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}