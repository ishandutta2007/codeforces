#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int Q;
bool vis[5<<17];
main()
{
	scanf("%d",&Q);
	int sz=0;
	queue<int>P2;
	priority_queue<pair<int,int> >P3;
	vector<int>ans;ans.reserve(Q);
	for(;Q--;)
	{
		int t;scanf("%d",&t);
		if(t==1)
		{
			int m;scanf("%d",&m);
			sz++;
			P2.push(sz);
			P3.push(make_pair(m,-sz));
		}
		else if(t==2)
		{
			while(vis[P2.front()])P2.pop();
			int id=P2.front();
			ans.push_back(id);
			vis[id]=true;
		}
		else
		{
			while(vis[-P3.top().second])P3.pop();
			int id=-P3.top().second;
			ans.push_back(id);
			vis[id]=true;
		}
	}
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?10:32);
}