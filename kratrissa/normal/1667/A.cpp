#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,a[N];ll ans;
void solve(){
	scanf("%d",&n),ans=1e18;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		ll res=0,t=0;
		for(int j=i-1;j;j--)res+=t/a[j]+1,t=(t/a[j]+1)*a[j];
		t=0;
		for(int j=i+1;j<=n;j++)res+=t/a[j]+1,t=(t/a[j]+1)*a[j];
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
}
int main(){
	T=1;
	while(T--)solve();
	return 0;
}