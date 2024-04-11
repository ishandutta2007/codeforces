#include<cstdio>
using namespace std;
long long N,K,S;
main()
{
	scanf("%lld%lld%lld",&N,&K,&S);
	if(K>S||K*(N-1)<S)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int now=1;
	for(int i=0;i<K;i++)
	{
		if(K-i-1<=S-(N-1))
		{
			S-=N-1;
			now=now==1?N:1;
		}
		else
		{
			int d=S-(K-i-1);
			S-=d;
			now=now>d?now-d:now+d;
		}
		printf("%d%c",now,i+1==K?10:32);
	}
}