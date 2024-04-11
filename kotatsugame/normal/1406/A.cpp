#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int cnt[101];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<=100;i++)cnt[i]=0;
		for(int i=0;i<N;i++)
		{
			int A;scanf("%d",&A);
			cnt[A]++;
		}
		int L=0,R=0;
		while(cnt[L]>=2)L++;
		R=L;
		while(cnt[R]>=1)R++;
		printf("%d\n",L+R);
	}
}