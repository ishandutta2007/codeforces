#include<cstdio>
using namespace std;
int T;
long long N;
main(){
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld",&N);
		while(N%2==0)N/=2;
		puts(N==1?"NO":"YES");
	}
}