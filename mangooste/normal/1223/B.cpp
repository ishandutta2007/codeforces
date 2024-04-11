#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

bool can(string& s, string& t) {
	int a[26];
	for (int i = 0; i < 26; i++)
		a[i] = 0;
	for (auto i : s)
		a[i - 'a']++;
	for (auto i : t)
		if (a[i - 'a'] > 0)
			return true;
	return false;
}

bool comp(ll a, ll b) {
	return a > b;
}

int run() {
	int n;
	cin >> n;
	vector <ll> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	ll x, y, k;
	int a, b;
	cin >> x >> a >> y >> b >> k;
	sort(p.begin(), p.end(), comp);
	vector <ll> pref(n + 1, 0LL);
	for (int i = 1; i <= n; i++)
		pref[i] = pref[i - 1] + p[i - 1] / 100LL;
	int l = 0, r = n + 1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		int z = 0;
		for (int i = 1; i <= m; i++)
			if (i % a == 0 && i % b == 0)
				z++;
		int num1 = m / a - z;
		int num2 = m / b - z;
		ll sum = pref[z] * z * (x + y);
		ll del = (pref[z + num1] - pref[z]) * x + (pref[z + num1 + num2] - pref[z + num1]) * y;
		del = max(del, (pref[z + num2] - pref[z]) * x + (pref[z + num2 + num1] - pref[z + num2]) * y);
		sum += del;
		if (sum >= k)
			r = m;
		else
			l = m;
	}
	if (r == n + 1)
		return -1;
	else
		return r;
}

signed main() {
	int q;
	cin >> q;
	while (q--) {
		//*
		string s, t;
		cin >> s >> t;
		if (can(s, t))
			cout << "YES\n";
		else
			cout << "NO\n";
		//*/
		/*
		cout << run() << '\n';
		//*/
	}
	return 0;
}