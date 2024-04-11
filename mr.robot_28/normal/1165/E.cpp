#include <bits/stdc++.h>

using namespace std;
#define int long long
int CONST = 998244353;
signed main() {
	int n;
	cin >> n;
	vector <int> A(n), B(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i< n; i++)
	{
		cin >> B[i];
	}
	for(int i = 0; i < n; i++)
	{
		A[i] *= (i + 1) * (n - i);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum = (sum + (A[i] % CONST) * (B[n - i - 1] % CONST) % CONST) % CONST;
	}
	cout << sum;
	return 0;
}