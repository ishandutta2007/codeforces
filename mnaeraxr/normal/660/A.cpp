#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	int ans = 0;

	for (int i = 1; i < n; ++i)
		if (__gcd(a[i - 1], a[i]) > 1) ++ans;

	cout << ans << endl;

	cout << a[0];

	for (int i = 1; i < n; ++i)
		if (__gcd(a[i - 1], a[i]) > 1)
			cout << " " << 1 << " " << a[i];
		else cout << " " << a[i];

	cout << endl;

	return 0;
}