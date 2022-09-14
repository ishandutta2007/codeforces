#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
int R[2<<17];
vector<int>G[2<<17];
int ans[2<<17];
main()
{
	scanf("%d%d",&N,&K);
	vector<pair<int,int> >A(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&R[i]);
		A[i]=make_pair(R[i],i);
	}
	sort(A.begin(),A.end());
	for(int i=0;i<K;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		if(R[x]<R[y])G[y].push_back(x);
		else if(R[x]>R[y])G[x].push_back(y);
	}
	int l=0;
	for(int i=0;i<N;i++)
	{
		while(A[l].first<A[i].first)l++;
		ans[A[i].second]=l+0-G[A[i].second].size();
	}
	for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?10:32);
}