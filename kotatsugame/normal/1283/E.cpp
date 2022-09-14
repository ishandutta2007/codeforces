#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int X[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&X[i]);
	sort(X,X+N);
	int mc=0;
	for(int i=0;i<N;)
	{
		int t=X[i]+2;
		while(i<N&&X[i]<=t)i++;
		mc++;
	}
	printf("%d ",mc);
	for(int i=0;i<N;i++)
	{
		if(i==0)
		{
			X[i]--;
			continue;
		}
		if(X[i-1]<X[i]-1)X[i]--;
		else if(X[i-1]==X[i]-1);
		else X[i]++;
	}
	int Mc=0;
	for(int i=0;i<N;i++)
	{
		if(i==0||X[i-1]!=X[i])Mc++;
	}
	printf("%d\n",Mc);
}