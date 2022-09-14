#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[3030];
int S;
int check(int X)
{
	int sum=0,cnt=0;
	for(int i=0;i<N;i++)
	{
		sum+=A[i];
		if(sum==X)
		{
			cnt++;
			sum=0;
		}
		else if(sum>X)return -1;
	}
	return sum?-1:cnt;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		S=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			S+=A[i];
		}
		int ans=1;
		for(int i=1;i*i<=S;i++)if(S%i==0)
		{
			int t=check(i);
			if(t>0&&ans<t)ans=t;
			t=check(S/i);
			if(t>0&&ans<t)ans=t;
		}
		printf("%d\n",N-ans);
	}
}