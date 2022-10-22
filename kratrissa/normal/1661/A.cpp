#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,a[N],b[N];
void solve(){
	scanf("%d",&n);ll ans=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<n;i++)ans+=min(abs(a[i]-a[i+1])+abs(b[i]-b[i+1]),abs(a[i]-b[i+1])+abs(b[i]-a[i+1]));
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}