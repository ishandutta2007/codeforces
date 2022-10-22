#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int n;
ll a[maxn],b[maxn];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%lld",a+i);
	if(n==1){
		printf("1 1\n%lld\n1 1\n0\n1 1\n0",-a[1]);
	}
	else{
		printf("1 1\n%lld\n2 %d\n",-a[1],n);
		for(ri i=2;i<=n;++i){
			b[i]=n-1+a[i];
			printf("%lld ",(b[i]+1)*(n-1));
			a[i]=b[i]*n;
		}
		printf("\n1 %d\n0 ",n);
		for(ri i=2;i<=n;++i)printf("%lld ",-a[i]);
	}
	return 0;
}