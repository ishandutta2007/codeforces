#include<cstdio>
#include<algorithm>
using namespace std;
int N[3];
long long S[3],M[3];
main()
{
	for(int i=0;i<3;i++)scanf("%d",&N[i]);
	for(int i=0;i<3;i++)
	{
		M[i]=1e9;
		for(int j=0;j<N[i];j++)
		{
			int A;scanf("%d",&A);
			S[i]+=A;
			M[i]=min(M[i],(long long)A);
		}
	}
	long long ans=-1e18;
	for(int i=0;i<3;i++)
	{
		for(int j=1;j<4;j++)
		{
			long long now=S[i];
			if(j==3)
			{
				now+=S[(i+1)%3];
				now+=S[(i+2)%3];
				now-=2*M[(i+1)%3];
				now-=2*M[(i+2)%3];
			}
			else if(j==2)
			{
				now+=S[(i+1)%3];
				now-=S[(i+2)%3];
			}
			else
			{
				now+=S[(i+2)%3];
				now-=S[(i+1)%3];
			}
			ans=max(ans,now);
		}
	}
	printf("%lld\n",ans);
}