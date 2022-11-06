#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e5 + 10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T --)
	{
		int n;
		cin >> n;
		vector<ll> a(n), s(n);
		rep0(i, n) cin >> a[i];
		sort(a.begin(), a.end());
		s[0] = a[0];
		rep(i, 1, n - 1) s[i] = s[i - 1] + a[i];
		if(a[0] * (n - 2) + s[n - 1] > 0) {cout << "INF\n"; continue;}
		if(a[n - 1] * (n - 2) + s[n - 1] < 0) {cout << "INF\n"; continue;}
		ll ans = (-1LL << 60);
		rep0(i, n)
		{
			ll pans = 0, t = -a[i];
			if(i) pans = (s[i - 1] + i * t) * (a[n - 1] + t);
			ans = max(ans, pans + (s[n - 1] - s[i] + (n - 1 - i) * t) * (a[0] + t) - (a[0] + t) * (a[n - 1] + t) - (n - 1) * t * t);
		}
		cout << ans << "\n";
	}
	return 0;
}