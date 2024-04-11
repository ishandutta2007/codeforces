#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int P[5<<17];
char S[5<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&P[i]);
	long long sum=0;
	scanf("%s",S);
	for(int i=0;i<N;i++)if(S[i]=='B')sum+=P[i];
	long long mx=0,now=0;
	for(int i=0;i<N;i++)
	{
		if(S[i]=='A')now+=P[i];
		else now-=P[i];
		mx=max(mx,now);
	}
	now=0;
	for(int i=N;i--;)
	{
		if(S[i]=='A')now+=P[i];
		else now-=P[i];
		mx=max(mx,now);
	}
	printf("%lld\n",sum+mx);
}