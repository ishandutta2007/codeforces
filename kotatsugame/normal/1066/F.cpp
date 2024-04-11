#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int N;
pair<int,int>L,R;
long long Lc,Rc;
int dist(pair<int,int>x,pair<int,int>y)
{
	return abs(x.first-y.first)+abs(x.second-y.second);
}
main()
{
	scanf("%d",&N);
	map<int,vector<pair<int,int> > >mp;
	for(int i=0;i<N;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		mp[max(x,y)].push_back(make_pair(x,y));
	}
	for(pair<int,vector<pair<int,int> > >e:mp)
	{
		vector<pair<int,int> >ps=e.second;
		sort(ps.begin(),ps.end(),[](pair<int,int>a,pair<int,int>b)
		{
			return a.first-a.second<b.first-b.second;
		});
		pair<int,int>nL=ps[0],nR=ps.back();
		long long nLc,nRc;
		nLc=min(Lc+dist(L,nR),Rc+dist(R,nR))+dist(nR,nL);
		nRc=min(Lc+dist(L,nL),Rc+dist(R,nL))+dist(nL,nR);
		L=nL;R=nR;
		Lc=nLc;Rc=nRc;
	}
	printf("%lld\n",min(Lc,Rc));
}