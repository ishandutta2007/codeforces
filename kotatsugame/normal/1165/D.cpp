#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N;
int D[303];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&D[i]);
		sort(D,D+N);
		long long U=(long long)D[0]*D[N-1];
		bool out=false;
		for(int i=0;i<N;i++)
		{
			if(U!=(long long)D[i]*D[N-1-i])
			{
				out=true;
			}
		}
		if(out)
		{
			puts("-1");
			continue;
		}
		vector<long long>d;
		for(long long i=2;i*i<=U;i++)if(U%i==0)
		{
			d.push_back(i);
			if(U/i>i)d.push_back(U/i);
		}
		sort(d.begin(),d.end());
		if(d!=vector<long long>(D,D+N))puts("-1");
		else printf("%lld\n",U);
	}
}