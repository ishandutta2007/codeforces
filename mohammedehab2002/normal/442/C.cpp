#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool cmp(int x,int y)
{
	return (a[x]<a[y]);
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v;
	set<int> s;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		s.insert(i);
		v.push_back(i);
	}
	sort(v.begin(),v.end(),cmp);
	long long ans=0;
	queue<int> q;
	for (int i:v)
	{
		auto it=s.find(i);
		if (it!=s.begin() && next(it)!=s.end())
		ans+=min(a[*prev(it)],a[*next(it)]);
		else
		{
			q.push(i);
			if (q.size()>2)
			{
				ans+=a[q.front()];
				q.pop();
			}
		}
		s.erase(it);
	}
	printf("%I64d",ans);
}