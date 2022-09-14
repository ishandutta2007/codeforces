#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int N;
int A[1515];
map<int,vector<pair<int,int> > >mp;
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<N;i++)
	{
		int s=0;
		for(int j=i;j<N;j++)
		{
			s+=A[j];
			mp[s].push_back(make_pair(i,j));
		}
	}
	vector<pair<int,int> >ans;
	for(pair<int,vector<pair<int,int> > >p:mp)
	{
		vector<pair<int,int> >a=p.second;
		sort(a.begin(),a.end(),[](pair<int,int>x,pair<int,int>y){return x.second<y.second;});
		vector<pair<int,int> >now;
		for(pair<int,int>q:a)
		{
			if(now.empty()||now.back().second<q.first)now.push_back(q);
		}
		if(ans.size()<now.size())ans=now;
	}
	printf("%d\n",ans.size());
	for(pair<int,int>p:ans)printf("%d %d\n",p.first+1,p.second+1);
}