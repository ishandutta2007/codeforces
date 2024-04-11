#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int k = 0; k < t; k++)
	{
		int n, x;
		cin >> n >> x;
		vector <pair <int, int> > A(n);
		int max = 0, max1 = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> A[i].first >> A[i].second;
			if(A[i].first > max)
			{
				max = A[i].first;
			}
			if(A[i].first - A[i].second > max1)
			{
				max1 = A[i].first - A[i].second;
			}
		}
		x -= max;
		if(max1 <= 0 && x > 0)
		{
			cout << -1 << "\n";
		}
		else if(x <= 0)
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << (x + max1 - 1) / max1 + 1 << "\n";
		}
	}
	return 0;
}