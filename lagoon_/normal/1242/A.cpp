#include<bits/stdc++.h>
using namespace std;
#define re register
int main()
{
	re long long n;
	scanf("%lld",&n);
	for(re long long i=2;i*i<=n;i++)if(!(n%i))
	{
		while(!(n%i))n/=i;
		if(n==1){printf("%lld\n",i);}
		else printf("1\n");
		return 0;
	}
	printf("%lld\n",n);
}