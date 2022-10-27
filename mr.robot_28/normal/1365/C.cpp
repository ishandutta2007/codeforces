#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n), b(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	vector <int> ind(n);
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
		b[i]--;
		ind[b[i]] = i;
	}
	int ans = 0;
	vector <int> minus(n, 0);
	for(int i = 0; i < n; i++)
	{
		minus[(n + ind[a[i]] - i) % n]++;
	}
	for(int i = 0; i < n; i++)
	{
		ans = max(ans, minus[i]);
	}
	cout << ans;
	return 0;
}