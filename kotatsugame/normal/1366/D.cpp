#include<cstdio>
using namespace std;
int N,A;
int d1[5<<17],d2[5<<17];
int pr[10000001];
main()
{
	for(int i=2;i<=10000000;i++)if(pr[i]==0)
	{
		pr[i]=i;
		for(int j=i+i;j<=10000000;j+=i)pr[j]=i;
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A);
		int p=pr[A],q=1;
		while(A%p==0)
		{
			A/=p;
			q*=p;
		}
		if(A==1)
		{
			d1[i]=d2[i]=-1;
		}
		else
		{
			d1[i]=q;
			d2[i]=A;
		}
	}
	for(int i=0;i<N;i++)printf("%d%c",d1[i],i+1==N?'\n':' ');
	for(int i=0;i<N;i++)printf("%d%c",d2[i],i+1==N?'\n':' ');
}