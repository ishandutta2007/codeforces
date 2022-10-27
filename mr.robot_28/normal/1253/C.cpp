#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n, m;
	cin >> n >> m;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int sum = 0;
	vector <int> cnt(m);
	for(int i = 0; i < n; i++)
	{
		cnt[i % m] += A[i];
		sum += cnt[i % m];
		cout << sum << " ";
	}
	
    return 0;
}