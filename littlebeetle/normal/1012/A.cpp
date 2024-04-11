#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
int n,i,a[N];
long long ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n*2;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+n+1);
	ans=1ll*(a[n]-a[1])*(a[n+n]-a[n+1]);
	for(i=2;i+n<=n*2;i++)
		ans=min(ans,1ll*(a[i+n-1]-a[i])*(a[n+n]-a[1]));
	printf("%lld",ans);
	
}