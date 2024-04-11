#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,ans=0;
	cin >> n;
	pair <int,int> p[n];
	for (i=0;i<n;i++)
	cin >> p[i].first >> p[i].second;
	sort (p,p+n);
	for (i=0;i<n;i++)
	{
		if (p[i].second>=ans)
		ans=p[i].second;
		else
		ans=p[i].first;
	}
	cout << ans;
}