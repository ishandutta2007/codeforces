#include<bits/stdc++.h>
using namespace std;
int n,m,t,x,y,z,res,lst;
long long msk;
priority_queue<pair<int,pair<long long,int> > > pq;
pair<int,pair<int,int> > edge[444];
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	pq.push(make_pair(0,make_pair(0,0)));
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		edge[i]=make_pair(z,make_pair(x,y));
	}
	sort(edge+1,edge+m+1);
	for (int i=1;i<=t;i++)
	{
		res=-pq.top().first;msk=pq.top().second.first;lst=pq.top().second.second;
	//	cout<<res<<" "<<msk<<" "<<lst<<endl;
		pq.pop();
		for (int j=lst+1;j<=m;j++)
		{
			if ((msk&(1ll<<edge[j].second.first)) || (msk&(1ll<<(edge[j].second.second+n)))) continue;
			pq.push(make_pair(-res-edge[j].first,make_pair(msk|(1ll<<edge[j].second.first)|(1ll<<(edge[j].second.second+n)),j)));
			break;
		}
		if (lst)
		{
			msk^=(1ll<<edge[lst].second.first);msk^=(1ll<<(edge[lst].second.second+n));
			for (int j=lst+1;j<=m;j++)
			{
				if ((msk&(1ll<<edge[j].second.first)) || (msk&(1ll<<(edge[j].second.second+n)))) continue;
				pq.push(make_pair(-res-edge[j].first+edge[lst].first,make_pair(msk|(1ll<<edge[j].second.first)|(1ll<<(edge[j].second.second+n)),j)));
				break;
			}
		}
	}
	printf("%d\n",res);
	return 0;
}