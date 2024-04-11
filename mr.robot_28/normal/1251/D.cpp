#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, s;
		cin >> n >> s;
		vector <pair <int, int> > A(n);
		for(int i = 0; i < n; i++)
		{
			cin >> A[i].first >> A[i].second;
		}
		sort(A.begin(), A.end());
		int l = 0, r = 2 * s / (n + 1) + 1;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			int s1 = 0;
			int k = 0;
			for(int i = n - 1; i >= 0; i--)
			{
				if(k < (n + 1) / 2 && A[i].second >= midd)
				{
					k++;
					s1 += max(midd, A[i].first);
				}
				else
				{
					s1 += A[i].first;
				}
			}
			if(k == (n + 1) / 2 && s1 <= s)
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		cout << l << "\n";
	}
    return 0;
}