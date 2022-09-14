#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
int X[2<<17];
vector<int>A[2<<17];
int cumsum[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d",&X[i]);
		X[i]--;
	}
	long long fst=0;
	for(int i=1;i<M;i++)if(X[i-1]!=X[i])
	{
		fst+=abs(X[i]-X[i-1]);
		A[X[i-1]].push_back(X[i]);
		A[X[i]].push_back(X[i-1]);
		if(X[i-1]<X[i])cumsum[X[i-1]+1]++,cumsum[X[i]]--;
		else cumsum[X[i]+1]++,cumsum[X[i-1]]--;
	}
	for(int i=1;i<N;i++)cumsum[i]+=cumsum[i-1];
	for(int i=0;i<N;i++)
	{
		long long now=fst;
		now-=cumsum[i];
		for(int x:A[i])
		{
			now-=abs(i-x);
			now+=x<i?x+1:x;
		}
		printf("%lld%c",now,i+1==N?10:32);
	}
}