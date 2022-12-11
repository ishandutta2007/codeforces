#include<cstdio>
#include<algorithm>
using namespace std;

int a[100001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		long long ans=0;
		for(int i=1;i<=n;i++)
			ans-=-1ll*(n-i)*a[i]+1ll*(i-1)*a[i];
		ans+=a[n];
		printf("%lld\n",ans);
	}
}