#include<cstdio>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
int N,Q;
int ansA[3<<17],ansB[3<<17];
main()
{
	scanf("%d%d",&N,&Q);
	deque<int>P;
	vector<pair<long long,int> >A;
	for(int i=0;i<N;i++)
	{
		int a;scanf("%d",&a);
		P.push_back(a);
	}
	for(int i=0;i<Q;i++)
	{
		long long m;scanf("%lld",&m);
		m--;
		A.push_back(make_pair(m,i));
	}
	sort(A.begin(),A.end());
	int id=0;
	for(int i=0;i<N;i++)
	{
		int nowA=P[0],nowB=P[1];
		P.pop_front();
		P.pop_front();
		while(id<Q&&A[id].first==i)
		{
			int ni=A[id].second;
			ansA[ni]=nowA;
			ansB[ni]=nowB;
			id++;
		}
		if(nowA>nowB)
		{
			P.push_front(nowA);
			P.push_back(nowB);
		}
		else
		{
			P.push_front(nowB);
			P.push_back(nowA);
		}
	}
	for(;id<Q;id++)
	{
		int X=(A[id].first-N)%(N-1);
		int ni=A[id].second;
		ansA[ni]=P[0];
		ansB[ni]=P[X+1];
	}
	for(int i=0;i<Q;i++)
	{
		printf("%d %d\n",ansA[i],ansB[i]);
	}
}