#include<cstdio>
using namespace std;
long long p10[19];
int T;
long long K;
char S[20];
long long cumsum(long long U)
{
	long long ret=0;
	int L=1;
	while(p10[L]-1<=U)
	{
		long long T=p10[L]-p10[L-1];
		long long V=2*U-p10[L]-p10[L-1]+3;
		ret+=T*V/2*L;
		L++;
	}
	long long T=U-p10[L-1]+1;
	long long V=U-p10[L-1]+2;
	ret+=T*V/2*L;
	return ret;
}
main()
{
	p10[0]=1;
	for(int i=1;i<19;i++)p10[i]=p10[i-1]*10;
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld",&K);
		K--;
		{
			long long l=0,r=1;
			while(cumsum(r)<=K)r*=2;
			while(r-l>1)
			{
				long long mid=(l+r)/2;
				if(cumsum(mid)<=K)l=mid;
				else r=mid;
			}
			K-=cumsum(l);
		}
		int L=1;
		while(true)
		{
			long long u=L*(p10[L]-p10[L-1]);
			if(K>=u)K-=u,L++;
			else break;
		}
		long long X=1;
		while(K>=p10[L-1]*L)X++,K-=p10[L-1]*L;
		for(int i=1;i<L;i++)
		{
			X*=10;
			while(K>=p10[L-i-1]*L)X++,K-=p10[L-i-1]*L;
		}
		int sz=0;
		while(X>0)
		{
			S[sz++]=X%10+'0';
			X/=10;
		}
		printf("%c\n",S[sz-K-1]);
	}
}