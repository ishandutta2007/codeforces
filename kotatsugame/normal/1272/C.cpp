#include<cstdio>
using namespace std;
int N,K;
char S[2<<17];
bool ok[500];
main()
{
	scanf("%d%d%s",&N,&K,S);
	for(int i=0;i<K;i++)
	{
		char c;
		scanf(" %c",&c);
		ok[c]=true;
	}
	long long ans=0;
	int now=0;
	for(int i=0;i<N;i++)
	{
		if(!ok[S[i]])now=0;
		else now++;
		ans+=now;
	}
	printf("%lld\n",ans);
}