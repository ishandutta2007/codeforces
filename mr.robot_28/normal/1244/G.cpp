#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	int n, k;
	cin >> n >> k;
	vector <int> par(n);
	for(int i = 0; i < n; i++)
	{
		par[i] = i;
	}
	int sum = (n + 1) * n / 2;
	if(sum > k)
	{
		cout << -1;
		return 0;
	}
	int j = 1, r = n;
	while(sum < k && j < r)
	{
		if(k - sum > r - j)
		{
			sum += r - j;
			r--;
			par[r] = j - 1;
			par[j - 1] = r;
		}
		else
		{
			par[k - sum - 1 + j] = j - 1;
			par[j - 1] = k - sum - 1 + j;
			sum += k - sum;
		}
		j++;
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans += max(par[i], i) + 1;
	}
	cout << ans << "\n";
	for(int i = 0; i < n ;i++)
	{
		cout << i + 1 << " "; 
	}
	cout << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << par[i] + 1 << " ";
	}
	return 0;
}