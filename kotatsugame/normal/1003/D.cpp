#include<cstdio>
using namespace std;
int N,Q;
int cnt[31];
main()
{
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		int id=0;
		while(A>>id+1)id++;
		cnt[id]++;
	}
	for(;Q--;)
	{
		int T;
		scanf("%d",&T);
		int ans=0;
		int now=0;
		for(int i=30;i>=0;i--)
		{
			now*=2;
			now+=T>>i&1;
			int t=now<cnt[i]?now:cnt[i];
			ans+=t;
			now-=t;
		}
		printf("%d\n",now?-1:ans);
	}
}