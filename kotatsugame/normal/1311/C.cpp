#include<cstdio>
using namespace std;
int T,N,M;
char S[2<<17];
long long cnt[26];
int sum[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%s",&N,&M,S);
		for(int i=0;i<=N;i++)sum[i]=0;
		for(int i=0;i<M;i++)
		{
			int p;scanf("%d",&p);sum[p-1]++;
		}
		sum[N-1]++;
		for(int i=N;i--;)sum[i]+=sum[i+1];
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=0;i<N;i++)cnt[S[i]-'a']+=sum[i];
		for(int i=0;i<26;i++)printf("%lld%c",cnt[i],i==25?10:32);
	}
}