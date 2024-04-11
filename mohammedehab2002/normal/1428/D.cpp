#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	vector<pair<int,int> > v;
	queue<int> q,q2;
	for (int i=n;i>0;i--)
	{
		if (a[i]==1)
		{
			v.push_back({i,i});
			q.push(i);
		}
		else if (a[i]==2)
		{
			if (q.empty())
			{
				printf("-1");
				return 0;
			}
			v.push_back({q.front(),i});
			q.pop();
			q2.push(i);
		}
		else if (a[i]==3)
		{
			if (q2.empty() && q.empty())
			{
				printf("-1");
				return 0;
			}
			if (!q2.empty())
			{
				v.push_back({i,i});
				v.push_back({i,q2.front()});
				q2.pop();
			}
			else
			{
				v.push_back({i,i});
				v.push_back({i,q.front()});
				q.pop();
			}
			q2.push(i);
		}
	}
	printf("%d\n",v.size());
	for (auto p:v)
	printf("%d %d\n",p.first,p.second);
}