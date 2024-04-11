#include <iostream>
#include <queue>
#include <set>
using namespace std;
queue<int> q[300005];
set<int> s;
int main()
{
	int n,a,cnt=1;
	scanf("%d%d",&n,&a);
	while (a--)
	{
		int t,x;
		scanf("%d%d",&t,&x);
		if (t==1)
		{
			q[x].push(cnt);
			s.insert(cnt);
			cnt++;
		}
		else if (t==2)
		{
			while (!q[x].empty())
			{
				int r=q[x].front();
				q[x].pop();
				if (s.find(r)!=s.end())
				s.erase(r);
			}
		}
		else
		{
			while (!s.empty() && *s.begin()<=x)
			s.erase(s.begin());
		}
		printf("%d\n",s.size());
	}
}