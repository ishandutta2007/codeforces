#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;
bool vis[1000005],vis2[1005];
vector<int> v;
int main()
{
	int n,m;
	queue<pair<int,int> > q;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);
		if (!vis2[a])
		{
			if (a>=n)
			q.push(make_pair(a-n,1));
			v.push_back(a-n);
			vis2[a]=1;
		}
	}
	while (!q.empty())
	{
		int c=q.front().first,l=q.front().second;
		q.pop();
		if (!c)
		{
			cout << l;
			return 0;
		}
		vis[c]=1;
		for (int i=0;i<v.size();i++)
		{
			if (c+v[i]<0 || c+v[i]>1000000)
			continue;
			if (!vis[c+v[i]])
			q.push(make_pair(c+v[i],l+1)),vis[c+v[i]]=1;
		}
	}
	cout << -1;
}