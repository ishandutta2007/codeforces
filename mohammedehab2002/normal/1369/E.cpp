#include <bits/stdc++.h>
using namespace std;
int a[100005];
int p[2][200005];
vector<int> inv[100005];
bool used[200005];
set<pair<int,int>,greater<pair<int,int> > > s;
void upd(int x)
{
	if (s.find({a[x],x})!=s.end())
	{
		s.erase({a[x],x});
		a[x]++;
		s.insert({a[x],x});
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&p[0][i],&p[1][i]);
		a[p[0][i]]--;
		a[p[1][i]]--;
		inv[p[0][i]].push_back(i);
		inv[p[1][i]].push_back(i);
	}
	for (int i=1;i<=n;i++)
	s.insert({a[i],i});
	stack<int> ans;
	while (!s.empty())
	{
		auto x=*s.begin();
		s.erase(s.begin());
		if (x.first<0)
		{
			printf("DEAD");
			return 0;
		}
		for (int i:inv[x.second])
		{
			if (!used[i])
			{
				used[i]=1;
				ans.push(i);
				upd(p[0][i]);
				upd(p[1][i]);
			}
		}
	}
	puts("ALIVE");
	while (!ans.empty())
	{
		printf("%d ",ans.top());
		ans.pop();
	}
}