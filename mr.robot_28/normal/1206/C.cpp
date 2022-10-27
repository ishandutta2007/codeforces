# include <bits/stdc++.h>
using namespace std;

signed main()
{
	int n;
	cin >> n;
	vector <int> A(2 * n);
	if(n % 2 == 0)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for(int i = 1; i <= 2 * n; i++)
	{
		int k = i / 2;
		if(k % 2 == 0)
		{
			A[(i - 1) / 2] = i;
		}
		else
		{
			A[n + (i - 1) / 2] = i;
		}
	}
	for(int i = 0; i < 2 * n; i++)
	{
		cout << A[i] << " ";
	}
	return 0;
}