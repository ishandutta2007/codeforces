#include<cstdio>
#include<algorithm>
using namespace std;
int n,g,b;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&g,&b);
		long long f=n+1>>1;
		long long k=(f-1)/g;
		printf("%I64d\n",max(k*b+f,1ll*n));
	}
	return 0;
}