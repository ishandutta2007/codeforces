#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int N,K;
main()
{
	scanf("%d%d",&N,&K);
	queue<int>P;
	set<int>ex;
	for(int i=0;i<N;i++)
	{
		int id;scanf("%d",&id);
		if(ex.find(id)!=ex.end());
		else
		{
			if(P.size()==K)
			{
				ex.erase(P.front());
				P.pop();
			}
			P.push(id);
			ex.insert(id);
		}
	}
	vector<int>ans;
	ans.reserve(P.size());
	while(!P.empty())
	{
		ans.push_back(P.front());
		P.pop();
	}
	printf("%d\n",(int)ans.size());
	for(int i=ans.size();i--;)printf("%d%c",ans[i],i?32:10);
}