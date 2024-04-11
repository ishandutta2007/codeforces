#include<cstdio>
using namespace std;
int N,K;
int P[2<<17],Q[2<<17];
int invQ[2<<17];
int cnt[2<<17];
char ans[2<<17];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&P[i]);
		P[i]--;
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",&Q[i]);
		Q[i]--;
		invQ[Q[i]]=i;
	}
	int mx=0;
	for(int i=0;i<N;i++)
	{
		if(invQ[P[i]]<mx)
		{
			cnt[invQ[P[i]]]++;
			cnt[mx]--;
		}
		else
		{
			mx=invQ[P[i]];
		}
	}
	int sz=0;
	for(int i=0;i<N;i++)
	{
		ans[Q[i]]='a'+sz;
		cnt[i+1]+=cnt[i];
		if(i+1<N&&cnt[i]==0)
		{
			sz++;
			if(sz==K)sz--;
		}
	}
	if(sz+1<K)puts("NO");
	else
	{
		puts("YES");
		for(int i=0;i<N;i++)putchar(ans[i]);
		puts("");
	}
}