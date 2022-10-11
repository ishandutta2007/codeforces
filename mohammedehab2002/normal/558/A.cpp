#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
	deque <pair<int,int> > c,d;
	int n,a,b,i;
	long long ans=0;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a >> b;
		if (a<0)
		c.push_back(make_pair(a,b));
		else
		d.push_back(make_pair(a,b));
	}
	sort (c.begin(),c.end());
	sort (d.begin(),d.end());
	while (c.size() && d.size())
	{
		ans+=d.front().second+c.back().second;
		d.pop_front();
		c.pop_back();
	}
	if (c.size())
	ans+=c.back().second;
	if (d.size())
	ans+=d.front().second;
	cout << ans;
}