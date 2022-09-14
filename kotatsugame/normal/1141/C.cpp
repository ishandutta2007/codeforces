#include<cstdio>
using namespace std;
int N;
int P[2<<17];
bool ex[2<<17];
long long Q[2<<17];
main()
{
	scanf("%d",&N);
	long long mx=0,mn=0;
	long long now=0;
	for(int i=1;i<N;i++)
	{
		int q;
		scanf("%d",&q);
		Q[i]=now+=q;
		if(mx<now)mx=now;
		if(mn>now)mn=now;
	}
	if(mx-mn!=N-1)puts("-1");
	else
	{
		P[0]=1-mn;
		ex[P[0]]=true;
		for(int i=1;i<N;i++)
		{
			if(ex[P[i]=P[0]+Q[i]])
			{
				puts("-1");
				return 0;
			}
			ex[P[i]]=true;
		}
		for(int i=0;i<N;i++)printf("%d%c",P[i],i+1==N?10:32);
	}
}