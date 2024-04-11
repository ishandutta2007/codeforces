#include <bits/stdc++.h>
using namespace std;
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> A(n);
		vector <int> ind(n);
		int l, r;
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
			A[i]--;
			ind[A[i]] = i;
		}
		l = ind[0];
		r = ind[0];
		cout << 1;
		for(int i = 1; i < n; i++)
		{
			l = min(ind[i], l);
			r = max(ind[i], r);
			if(r - l == i)
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
		cout << "\n";
	}
    return 0;
}