#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
 
 
using namespace std;
 
 
typedef long double ld;
typedef long long ll;
 
 
#define x first
#define y second
#define int long long
 
 
 
vector<pair<int, int>> st;
vector<int> jump;
 
 
ld inter(pair<int, int> a, pair<int, int> b) {
	return (b.y - a.y) / ((ld)a.x - b.x);
}
 
 
void add(pair<int, int> a) {
	while (st.size() > 1 && inter(a, st[st.size() - 2]) < inter(a, st.back())) {
		st.pop_back();
	}
	if (!st.empty()) {
		auto el = st.back();
		jump[-a.x] = -el.x;
	}
	st.push_back(a);
}
 
 
 
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	jump.resize(n);
	vector<int> a(n);
	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pref[i + 1] = pref[i] + a[i];
	}
	for (int i = n; i >= 0; i--) {
		add({-i, pref[i]});
	}
	int i = 0;
	cout << setprecision(19) << fixed;
	while (i < n) {
		int t = jump[i];
		ld ans = (pref[t] - pref[i]) / ((ld)t - i);
		for (int k = i; k < t; k++) {
			cout << ans << '\n';
		}
		i = jump[i];
	}
	return 0;
}