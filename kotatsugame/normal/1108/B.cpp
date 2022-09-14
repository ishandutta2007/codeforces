#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	vector<int>D(N);
	for(int i=0;i<N;i++)scanf("%d",&D[i]);
	sort(D.begin(),D.end());
	int x=D.back();
	vector<int>X;
	for(int i=1;i<=x;i++)if(x%i==0)X.push_back(i);
	vector<int>Y;
	int xi=0;
	for(int i=0;i<N;i++)
	{
		while(D[i]>X[xi])xi++;
		if(D[i]==X[xi])xi++;
		else Y.push_back(D[i]);
	}
	printf("%d %d\n",x,Y.back());
}