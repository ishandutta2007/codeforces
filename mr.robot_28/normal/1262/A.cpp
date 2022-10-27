#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <pair <int, int> > A(n);
		int minleft = 0;
		int maxright = 1e9;
		for(int i = 0; i < n; i++)
		{
			cin >> A[i].first >> A[i].second;
			minleft = max(minleft, A[i].first);
			maxright = min(maxright, A[i].second);;
		}
		if(minleft < maxright)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << minleft - maxright << "\n";
		}
	}
	return 0;
}