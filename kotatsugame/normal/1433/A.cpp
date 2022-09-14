#include<cstdio>
using namespace std;
int T[10000];
main()
{
	int cnt=0;
	for(int i=1;i<=9;i++)
	{
		int now=0;
		for(int j=0;j<4;j++)
		{
			now=now*10+i;
			cnt+=j+1;
			T[now]=cnt;
		}
	}
	int N;scanf("%d",&N);
	for(;N--;)
	{
		int t;scanf("%d",&t);
		printf("%d\n",T[t]);
	}
}