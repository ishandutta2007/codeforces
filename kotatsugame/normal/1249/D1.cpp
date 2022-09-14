#include<cstdio>
#include<set>
#include<vector>
using namespace std;
int N,K;
vector<pair<int,int> >L[2<<17];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		int l,r;scanf("%d%d",&l,&r);
		l--;
		L[l].push_back(make_pair(r,i));
	}
	set<pair<int,int> >S;
	vector<int>ans;
	for(int i=0;i<2<<17;i++)
	{
		while(!S.empty()&&S.begin()->first<=i)S.erase(S.begin());
		for(pair<int,int>p:L[i])S.insert(p);
		while(S.size()>K)
		{
			auto it=S.end();
			it--;
			ans.push_back(it->second);
			S.erase(it);
		}
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i]+1,i+1==ans.size()?10:32);
}