#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;
	deque<int> d;
	for (int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		d.push_back(a);
	}
	sort(d.begin(),d.end());
	int c=0;
	while (d.size())
	{
		if (d[0]>=2*k)
		{
			c+=d[0]/(2*k);
			d[0]%=(2*k);
			if (!d[0])
			d.pop_front();
		}
		if (d.size())
		{
			d[0]-=k;
			if (d[0]<=0)
			d.pop_front();
			c++;
		}
		if (d.size())
		{
			d[0]-=k;
			if (d[0]<=0)
			d.pop_front();
		}
	}
	cout << c;
}