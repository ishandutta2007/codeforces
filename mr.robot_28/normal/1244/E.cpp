#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	int n, k;
	cin >> n >> k;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int l = 0, r = n - 1;
	while(r > l)
	{
		while(l < n - 1 && A[l] == A[l + 1])
		{
			l++;
		}
		while(r > 0 && A[r] == A[r - 1])
		{
			r--;
		}
		if(r > l)
		{
			if(n - r < l + 1)
			{
				if(k / (n - r) == 0)
				{
					break;
				}
				int p = k / (n - r);
				k -= min(A[r] - A[r - 1], p) * (n - r);
				A[r] -= min(A[r] - A[r - 1], p);
			}
			else
			{
				if(k / (l + 1) == 0)
				{
					break;
				}
				int p = k / (l + 1);
				k -= min(A[l + 1] - A[l], p) * (l + 1);
				A[l] += min(A[l + 1] - A[l], p);
			}
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	cout << A[r] - A[l];
	return 0;
}