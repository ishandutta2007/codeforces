#include<cstdio>
using namespace std;
int N,K;
int cnt[30];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<30;i++)if(N>>i&1)
	{
		cnt[i]++;
		K--;
	}
	if(K<0)
	{
		puts("NO");
		return 0;
	}
	for(int i=30;--i;)
	{
		while(K>0&&cnt[i]>0)
		{
			K--;
			cnt[i]--;
			cnt[i-1]+=2;
		}
	}
	if(K>0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	bool fst=true;
	for(int i=0;i<30;i++)for(int j=0;j<cnt[i];j++)
	{
		if(fst)fst=false;
		else putchar(' ');
		printf("%d",1<<i);
	}
	puts("");
}