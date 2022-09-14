#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		queue<pair<int,int> >P;
		P.push(make_pair(0,N));
		vector<pair<int,int> >X;
		while(!P.empty())
		{
			int l=P.front().first,r=P.front().second;
			P.pop();
			int mid=(l+r-1)/2;
			X.push_back(make_pair(l-r,mid));
			if(l<mid)P.push(make_pair(l,mid));
			if(mid+1<r)P.push(make_pair(mid+1,r));
		}
		sort(X.begin(),X.end());
		for(int i=0;i<N;i++)A[X[i].second]=i+1;
		for(int i=0;i<N;i++)printf("%d%c",A[i],i+1==N?'\n':' ');
	}
}