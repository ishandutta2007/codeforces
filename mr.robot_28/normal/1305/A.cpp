#include<bits/stdc++.h>
using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> a(n);
		vector <int> b(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for(int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for(int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
		for(int i = 0; i < n; i++)
		{
			cout << b[i] << " ";
		}
		cout << "\n";
	}
    return 0;
}