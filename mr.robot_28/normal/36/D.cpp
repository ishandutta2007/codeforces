#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, k;
	cin >> t >> k;
	k++;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		if(min(n, m) % k == 0)
		{
			cout << "+\n";
			continue;
		}
		if(k == 2)
		{
			if(n % 2 == 0 || m % 2 == 0)
			{
				cout << "+\n";
			}
			else
			{
				cout << "-\n";
			}
			continue;
		}
		int r = min(n, m) / k;
		if((n + m + r) % 2 == 0)
		{
			cout << "-\n";
		}
		else
		{
			cout << "+\n";
		}
	}
	return 0;
}