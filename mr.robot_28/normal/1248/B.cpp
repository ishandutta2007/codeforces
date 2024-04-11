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
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int sum1 = 0, sum2 = 0;
	sort(A.begin(), A.end());
	for(int i = 0; i < n / 2; i++)
	{
		sum1 += A[i];
	}
	for(int i = n / 2; i < n; i++)
	{
		sum2 += A[i];
	}
	cout << sum1 * sum1 + sum2 * sum2;
    return 0;
}