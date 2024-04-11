#include<cstdio>
using namespace std;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int T,N,A[1<<17];
long long I[1<<17];
main()
{
	I[0]=2;
	for(int i=1;i<1<<17;i++)
	{
		if(I[i-1]>(int)1e9)I[i]=I[i-1];
		else I[i]=I[i-1]/gcd(i+2,I[i-1])*(i+2);
	}
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		bool ok=true;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			if(A[i]%I[i]==0)ok=false;
		}
		puts(ok?"YES":"NO");
	}
}