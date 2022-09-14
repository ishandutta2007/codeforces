#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
bool R[2<<17];
main()
{
	scanf("%d",&N);
	vector<pair<int,int> >A(N);
	for(int i=0;i<N;i++)
	{
		A[i].second=i;
		scanf("%d",&A[i].first);
	}
	sort(A.begin(),A.end());
	if(N<=3)
	{
		puts("1");
		return 0;
	}
	int D=A[2].first-A[1].first;
	bool flag=1;
	for(int i=3;i<N;i++)flag&=D==A[i].first-A[i-1].first;
	if(flag)
	{
		printf("%d\n",A[0].second+1);
		return 0;
	}
	D=A[2].first-A[0].first;
	flag=1;
	for(int i=3;i<N;i++)flag&=D==A[i].first-A[i-1].first;
	if(flag)
	{
		printf("%d\n",A[1].second+1);
		return 0;
	}
	D=A[1].first-A[0].first;
	R[N-1]=true;
	for(int i=N-1;i--;)
	{
		R[i]=R[i+1]&&(A[i+1].first-A[i].first==D);
	}
	bool now=true;
	for(int i=0;i<N-2;i++)
	{
		if(now&&R[i+2]&&D==A[i+2].first-A[i].first)
		{
			printf("%d\n",A[i+1].second+1);
			return 0;
		}
		now&=D==A[i+1].first-A[i].first;
	}
	if(now)
	{
		printf("%d\n",A[N-1].second+1);
		return 0;
	}
	puts("-1");
}