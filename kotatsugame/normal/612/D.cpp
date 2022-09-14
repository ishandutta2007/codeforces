#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
main()
{
	scanf("%d%d",&N,&K);
	vector<pair<int,int> >X;
	X.reserve(N*2);
	for(int i=0;i<N;i++)
	{
		int l,r;scanf("%d%d",&l,&r);
		X.emplace_back(l,-1);
		X.emplace_back(r,1);
	}
	sort(X.begin(),X.end());
	vector<int>ret;
	int now=0;
	for(pair<int,int>p:X)
	{
		int prv=now;
		now-=p.second;
		if(prv<K&&now==K)ret.push_back(p.first);
		if(prv==K&&now<K)ret.push_back(p.first);
	}
	printf("%d\n",ret.size()/2);
	for(int i=0;i<ret.size();i+=2)
	{
		printf("%d %d\n",ret[i],ret[i+1]);
	}
}