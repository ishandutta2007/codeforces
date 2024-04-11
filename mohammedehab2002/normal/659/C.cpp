#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main()
{
	deque <long long> d,ans;
	int n;
	long long m,p=0;
	cin >> n >> m;
	for (int i=0;i<n;i++)
	{
		long long a;
		cin >> a;
		d.push_back(a);
	}
	sort(d.begin(),d.end());
	for (long long i=1;p+i<=m;i++)
	{
		if (d.front()==i)
		{
			d.pop_front();
			continue;
		}
		p+=i;
		ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (int i=0;i<ans.size();i++)
	cout << ans[i] << ' ';
}