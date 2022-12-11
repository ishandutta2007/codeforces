#include<cstdio>

using namespace std;

const int md=1000000007;
long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		long long n;
		scanf("%lld",&n);
		long long d=1;
		long long ans=n%md;
		for(long long o=1;o<=n;++d,o=o*d/gcd(o,d))
			ans=(ans+((n/o)%md))%md;
		printf("%lld\n",ans);
	}
}