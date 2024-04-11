#include<cstdio>
using namespace std;
int N,M;
int A[3<<17];
bool check(int T)
{
	int pre=0;
	for(int i=0;i<N;i++)
	{
		int d=(pre-A[i]+M)%M;
		if(d>T)
		{
			if(pre<A[i])pre=A[i];
			else if(pre-A[i]>T)
			{
				return false;
			}
		}
	}
	return true;
}
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int L=-1,R=M;
	while(R-L>1)
	{
		int mid=(L+R)/2;
		if(check(mid))R=mid;
		else L=mid;
	}
	printf("%d\n",R);
}