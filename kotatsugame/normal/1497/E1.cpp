#include<cstdio>
#include<set>
using namespace std;
int T,N,K;
int A[2<<17];
const int LIM=1e7;
int SQ[LIM+1];
main()
{
	scanf("%d",&T);
	for(int i=1;i*i<=LIM;i++)
	{
		for(int j=i*i;j<=LIM;j+=i*i)SQ[j]=i*i;
	}
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)
		{
			int X;scanf("%d",&X);
			A[i]=X/SQ[X];
		}
		int cnt=1;
		set<int>S;
		for(int i=0;i<N;i++)
		{
			if(S.find(A[i])!=S.end())
			{
				cnt++;
				S.clear();
			}
			S.insert(A[i]);
		}
		printf("%d\n",cnt);
	}
}