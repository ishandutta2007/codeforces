#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
ll n;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%lld",&n);
		if(n%2050){
			puts("-1");
			continue;
		}
		n/=2050;
		int sum=0;
		while(n)
			sum+=n%10,n/=10;
		printf("%d\n",sum);
	}
	return 0;
}