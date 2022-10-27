#include<bits/stdc++.h>
using namespace std;

signed main()
{
	int n;
	cin >> n;
	int imax = 0;
	vector <int> a(n);
	for(int i = 1; i < n; i++)
	{
		cout << "? " << imax + 1 << " " << i + 1 << endl;
		fflush(stdout);
		int k1;
		cin >> k1;
		cout << "? " << i + 1 << " " << imax + 1 << endl;
		fflush(stdout);
		int k2;
		cin >> k2;
		if(k1 > k2)
		{
			a[imax] = k1;
			imax = i;
		}
		else
		{
			a[i] = k2;
		}
	}
	a[imax] = n;
	cout << "! ";
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	fflush(stdout);
	return 0;
}