#include<cstdio>
using namespace std;
int T,N;
char S[1<<20];
int cnt[1<<20];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%s",&N,S);
		for(int i=0;i<N;i++)cnt[i]=0;
		int sc=0;
		long long now=0;
		for(int i=0;i<N;i++)
		{
			if(S[i]=='*')
			{
				now+=i-sc;
				cnt[i-sc]++;
				sc++;
			}
		}
		long long ans=now;
		int L=0,R=sc;
		for(int i=1;i+sc<=N;i++)
		{
			L+=cnt[i-1];
			R-=cnt[i-1];
			now-=R;
			now+=L;
			if(ans>now)ans=now;
		}
		printf("%lld\n",ans);
	}
}