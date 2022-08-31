#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=100010;

int n,tot;
vector<int> v[MaxN];
pair<int,int> w[MaxN];
vector<pair<int,int> > ans;

void build(int f,int x,int p)
{
	int pre=f;
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it) if (*it!=p)
	{
		int now=++tot;
		w[now]=make_pair(x,*it);
		if (pre) ans.push_back(make_pair(pre,now));
		pre=now;
		build(now,*it,x);
	}
}

int main()
{
	cin>>n;
	for (int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	build(0,1,0);
	cout<<ans.size()+1<<endl;
	for (int i=1;i<=ans.size()+1;++i)
		printf("2 %d %d\n",w[i].first,w[i].second);
	for (int i=0;i<ans.size();++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}