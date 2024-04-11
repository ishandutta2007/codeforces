#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,d[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",d+i);
		sort(d+2,d+n+1);
		ll sum=0,ans=0;
		for(int i=3; i<=n; i++){
			sum+=d[i-2];
			ans-=(i-2ll)*d[i]-sum;
		}
		printf("%lld\n",ans);
	}
	return 0;
}