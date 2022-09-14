#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	map<int,vector<int> >mp;
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		mp[A].push_back(i);
	}
	vector<pair<int,int> >E;
	for(pair<int,vector<int> >p:mp)
	{
		int l=p.second[0],r=p.second.back();
		if(l<r)E.push_back(make_pair(l,r));
	}
	sort(E.begin(),E.end());
	int ans=N-1;
	for(int i=0;i<E.size();)
	{
		int l=E[i].first,r=E[i].second;
		while(i<E.size()&&r>=E[i].first)
		{
			r=max(r,E[i].second);
			i++;
		}
		ans-=r-l;
	}
	int ret=1;
	while(ans--)ret=ret*2%998244353;
	printf("%d\n",ret);
}