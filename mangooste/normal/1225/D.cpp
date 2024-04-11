//#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES

//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <cstdio>

typedef long long ll;
typedef long double ld;

using namespace std;

pair <ll, ll> get(ll a, ll k) {
	if (a == 1) {
		return { 1, 1 };
	}
	vector <pair <ll, ll>> v;
	for (ll i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			ll st = 0;
			while (a % i == 0) {
				st++, a /= i;
			}
			st %= k;
			if (st != 0) {
				v.push_back({ i, st });
			}
		}
	}
	if (a != 1) {
		v.push_back({ a, 1 });
	}
	ll ans1 = 1;
	ll ans2 = 1;
	for (auto i : v) {
		for (int j = 0; j < i.second; j++) {
			ans1 *= i.first;
		}
		for (int j = 0; j < k - i.second; j++) {
			ans2 *= i.first;
		}
	}
	return { ans1, ans2 };
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	ll n, k;
	cin >> n >> k;
	vector <ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <pair <ll, ll>> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = get(a[i], k);
	}
	ll ans = 0;
	map <ll, ll> m;
	m[v[0].first]++;
	for (int i = 1; i < n; i++) {
		ans += m[v[i].second];
		m[v[i].first]++;
	}
	cout << ans << '\n';
	return 0;
}