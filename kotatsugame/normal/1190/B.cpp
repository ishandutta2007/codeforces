#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int A[1<<17];
void fst(){puts("sjfnb");}
void snd(){puts("cslnb");}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	sort(A,A+N);
	int cnt=0;
	for(int i=1;i<N;i++)if(A[i-1]==A[i])
	{
		if(A[i]==0)
		{
			snd();
			return 0;
		}
		if(cnt||!(i-2<0||A[i-2]<A[i-1]-1))
		{
			snd();
			return 0;
		}
		cnt++;
	}
	long long sum=0;
	for(int i=0;i<N;i++)sum+=A[i]-i;
	if(sum%2==0)snd();
	else fst();
}