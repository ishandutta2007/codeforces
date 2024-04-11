#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b,k;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&k);
		int t=__gcd(a,b);
		a/=t,b/=t;
		if(a>b) swap(a,b);
		if(a*(k-1ll)+1<b) puts("REBEL");
		else puts("OBEY");
	}
	return 0;
}