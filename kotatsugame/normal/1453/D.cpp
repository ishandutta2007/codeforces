#include<cstdio>
using namespace std;
int T;
long long K;
int N;
int A[2020];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld",&K);
		if(K%2==1)
		{
			puts("-1");
			continue;
		}
		K-=2;
		for(int i=0;i<2000;i++)A[i]=0;
		A[0]=1;
		int p=0;
		while(K>=8)
		{
			int i=0;
			while(K>>i+1)i++;
			p+=i-1;
			if(p>=2000)break;
			A[p]=1;
			K-=1LL<<i;
			K+=2;
		}
		if(K==6)
		{
			p+=2;
			A[p]=1;
		}
		else if(K==4||K==2)
		{
			while(K>=2)
			{
				K-=2;
				A[++p]=1;
			}
		}
		if(p>=2000)puts("-1");
		else
		{
			printf("%d\n",p+1);
			for(int i=0;i<=p;i++)printf("%d%c",A[i],i==p?'\n':' ');
		}
	}
}