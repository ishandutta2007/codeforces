#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
main()
{
	scanf("%d%d",&N,&K);
	map<int,int>mp;
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		mp[A]++;
	}
	vector<pair<int,int> >C;
	for(pair<int,int>p:mp)C.push_back(make_pair(p.second,p.first));
	sort(C.begin(),C.end());
	reverse(C.begin(),C.end());
	int L=1,R=N/K+1;
	while(R-L>1)
	{
		int mid=(L+R)/2;
		int len=0;
		for(pair<int,int>p:C)len+=p.first/mid;
		if(len>=K)L=mid;
		else R=mid;
	}
	vector<int>T;
	for(pair<int,int>p:C)
	{
		int u=p.first;
		while(T.size()<K&&u>=L)
		{
			u-=L;
			T.push_back(p.second);
		}
	}
	for(int i=0;i<K;i++)printf("%d%c",T[i],i+1==K?10:32);
}