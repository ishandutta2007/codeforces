#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
int K[2<<17],iK[2<<17];
vector<int>G[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&iK[i]);
	}
	vector<pair<int,int> >A(M);
	for(int i=0;i<M;i++)
	{
		int d,t;scanf("%d%d",&d,&t);
		G[d].push_back(t-1);
	}
	int L=0,R=400000;
	while(R-L>1)
	{
		int mid=(L+R)/2;
		for(int i=0;i<N;i++)K[i]=iK[i];
		int rest=0,now=mid;
		for(int i=mid;i>=0;i--)
		{
			if(i<now)now--,rest++;
			if(i<2<<17)
			{
				for(int t:G[i])
				{
					int mn=min(K[t],now);
					K[t]-=mn;
					now-=mn;
				}
			}
		}
		for(int i=0;i<N;i++)rest-=2*K[i];
		if(rest>=0)R=mid;
		else L=mid;
	}
	printf("%d\n",R);
}