#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> b(n);
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	vector <int> a(n);
	a[0] = b[0];
	int mx = a[0];
	for(int i = 1; i < n; i++)
	{
		a[i] = b[i]  + mx;
		mx = max(mx, a[i]);
	}
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}