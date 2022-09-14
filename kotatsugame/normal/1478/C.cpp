#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
long long D[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<2*N;i++)scanf("%lld",&D[i]);
		sort(D,D+2*N);
		bool ok=true;
		for(int i=0;i<N;i++)
		{
			if(D[i*2]!=D[i*2+1])
			{
				ok=false;
				break;
			}
			if(i>0&&D[i*2]==D[i*2-1])
			{
				ok=false;
				break;
			}
		}
		if(!ok)
		{
			puts("NO");
			continue;
		}
		long long U=D[0];
		for(int i=0;i<N-1;i++)
		{
			long long d=D[i*2+2]-D[i*2];
			if(d%(i*2+2)!=0)
			{
				ok=false;
				break;
			}
			long long A=d/(i*2+2);
			U-=A*(N*2-i*2-2);
		}
		if(!ok||U<=0||U%(2*N)!=0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
	}
}