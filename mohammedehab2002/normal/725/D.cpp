#include <iostream>
#include <stdio.h>
#include <queue>
#include <set>
using namespace std;
multiset<pair<long long,int> > s;
priority_queue<pair<pair<long long,long long>,int> > q;
int main()
{
	int n;
	long long c;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		long long a,b;
		scanf("%I64d%I64d",&a,&b);
		if (!i)
		{
			c=a;
			continue;
		}
		if (a>c)
		s.insert(make_pair(b-a+1,i));
		else
		q.push(make_pair(make_pair(a,b),i));
	}
	int ans=s.size();
	while (s.size() && c>0)
	{
		long long t=(*s.begin()).first,i=(*s.begin()).second;
		c-=t;
		if (c<0)
		break;
		s.erase(s.begin());
		while (!q.empty() && q.top().first.first>c)
		{
			long long a=q.top().first.second-q.top().first.first+1,b=q.top().second;
			q.pop();
			s.insert(make_pair(a,b));
		}
		ans=min(ans,(int)s.size());
	}
	printf("%d",ans+1);
}