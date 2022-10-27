#include <bits/stdc++.h>
 
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <pair <int, int> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first >> A[i].second;
	}
	if(n % 2 != 0)
	{
		cout << "NO";
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		int k = (i + n / 2) % n;
		if((A[(i + 1) % n].first - A[i].first) != -(A[(k + 1) % n].first - A[k].first) ||
		(A[(i + 1) % n].second - A[i].second) != -(A[(k + 1) % n].second - A[k].second))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}