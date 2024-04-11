#include<cstdio>
#include<set>
using namespace std;
int T;
main()
{
	set<long long>S;
	for(long long i=1;i*i*i<=1000000000000;i++)
	{
		S.insert(i*i*i);
	}
	scanf("%d",&T);
	for(;T--;)
	{
		bool fn=false;
		long long X;scanf("%lld",&X);
		for(long long s:S)
		{
			if(s>X)break;
			long long T=X-s;
			if(S.find(T)!=S.end())
			{
				fn=true;
				break;
			}
		}
		puts(fn?"YES":"NO");
	}
}