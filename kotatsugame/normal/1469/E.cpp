#include<cstdio>
using namespace std;
int T,N,K;
int vis[1<<20],tm;
char S[1<<20];
int zero[1<<20];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		tm++;
		scanf("%d%d\n%s",&N,&K,S);
		zero[0]=0;
		for(int i=0;i<N;i++)
		{
			zero[i+1]=zero[i]+(S[i]=='0');
		}
		unsigned int now=0;
		for(int i=0;i<N;i++)
		{
			now=now<<1|'1'-S[i];
			if(K>=20)now&=(1<<20)-1;
			else now&=(1<<K)-1;
			if(i>=K-1)
			{
				if(K>=20?zero[i-19]-zero[i-K+1]==0:true)
				{
					vis[now]=tm;
				}
			}
		}
		int ans=0;
		while(ans<1<<20&&vis[ans]==tm)ans++;
		if(ans>=1<<20)puts("NO");
		else if(K<20&&ans>=1<<K)puts("NO");
		else
		{
			puts("YES");
			while(K>20)K--,printf("0");
			while(K>0)
			{
				K--;
				printf("%d",ans>>K&1);
			}
			puts("");
		}
	}
}