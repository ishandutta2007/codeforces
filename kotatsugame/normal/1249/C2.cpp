#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T;
long long N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld",&N);
		long long N_=N;
		bool two=false;
		int p=-1,c=0;
		while(N_>0)
		{
			if(N_%3==2)two=true;
			else if(N_%3==0)
			{
				if(two)p=c,two=false;
			}
			c++;
			N_/=3;
		}
		if(two)p=c;
		long long ans=N;
		if(p>=0)
		{
			long long t=1;
			for(;p--;)t*=3;
			ans-=ans%t;
			ans+=t;
		}
		printf("%lld\n",ans);
	}
}