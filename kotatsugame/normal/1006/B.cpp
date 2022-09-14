#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
main()
{
	scanf("%d%d",&N,&K);
	vector<pair<int,int> >X(N);
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		X[i]=make_pair(A,i);
	}
	sort(X.begin(),X.end());
	vector<int>id(K);
	int ans=0;
	for(int i=0;i<K;i++)
	{
		id[i]=X[N-i-1].second;
		ans+=X[N-i-1].first;
	}
	printf("%d\n",ans);
	sort(id.begin(),id.end());
	id.back()=N-1;
	for(int i=0;i<K;i++)printf("%d%c",id[i]-(i?id[i-1]:-1),i+1==K?10:32);
}