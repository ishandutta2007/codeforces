#include<cstdio>
using namespace std;
int N;
int T[]={4,8,15,16,23,42};
main()
{
	scanf("%d",&N);
	int cnt[7]={};
	cnt[0]=N;
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		int id=0;
		while(T[id]!=A)id++;
		if(cnt[id]>0)
		{
			cnt[id]--;
			cnt[id+1]++;
		}
	}
	printf("%d\n",N-6*cnt[6]);
}