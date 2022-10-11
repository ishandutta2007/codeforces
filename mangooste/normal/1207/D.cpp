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

#define FAST ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr)
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FIXED cout << fixed << setprecision(10)
#define all(a) begin(a), end(a)
#define pb(a) push_back(a)
#define sz(a) a.size()
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef long double ld;

using namespace std;

const ll mod = 998244353;

bool flag = 1;
int n, ind = 0;
vector <pair <int, int>> v;
vector <int> v1, v2;
ll ans1 = 1, ans2 = 1, ans12 = 1;
vector <ll> fact;

signed main() {
	FAST;
	FIXED;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	fact.resize(n + 1, 1);
	for (int i = 2; i <= n; i++) {
		fact[i] = fact[i - 1] * i % mod;
	}
	v1.resize(n + 1, 0);
	for (auto i : v) {
		v1[i.first]++;
	}
	for (auto i : v1) {
		ans1 = (ans1 * fact[(i == 0) ? 0 : i]) % mod;
	}
	v2.resize(n + 1, 0);
	for (auto i : v) {
		v2[i.second]++;
	}
	for (auto i : v2) {
		ans2 = (ans2 * fact[(i == 0) ? 0 : i]) % mod;
	}
	sort(all(v));
	for (int i = 1; i < n; i++) {
		if (v[i].second < v[i - 1].second) {
			ans12 = 0;
			flag = 0;
			break;
		}
	}
	if (flag) {
		while (ind < n) {
			int i1 = lower_bound(all(v), v[ind]) - v.begin();
			int i2 = upper_bound(all(v), v[ind]) - v.begin();
			ans12 = ans12 * fact[i2 - i1] % mod;
			ind = i2;
		}
	}
	cout << (2 * mod + fact[n] - ans1 - ans2 + ans12) % mod << '\n';
	return 0;
}