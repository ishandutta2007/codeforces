#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

vector<pair<int, int>> get(string s, string t) {
	while (!s.empty() && s.back() == 'a')
		s.pop_back();
	while (!t.empty() && t.back() == 'b')
		t.pop_back();
	int cnt = 0;
	vector<int> sv;
	vector<int> tv;
	for (int i = 0; i < s.size(); ++i) {
		++cnt;
		if (i == s.size() - 1 || s[i + 1] != s[i])
			sv.push_back(cnt), cnt = 0;
	}
	cnt = 0;
	for (int i = 0; i < t.size(); ++i) {
		++cnt;
		if (i == t.size() - 1 || t[i + 1] != t[i])
			tv.push_back(cnt), cnt = 0;
	}
	reverse(sv.begin(), sv.end());
	reverse(tv.begin(), tv.end());
	if (sv.empty() && tv.empty()) {
		return {};
	}
	int fl = 0;
	if (tv.empty())
		swap(tv, sv), fl = 1;
	vector<pair<int, int> > ans;
	if (sv.empty()) {
		if (tv.size() % 4 == 0) {
			int sum = tv[tv.size() / 2];
			for (int i = tv.size() / 2 + 1; i < tv.size(); ++i) {
				sum += tv[i];
				sv.push_back(tv[i]);
			}
			tv.resize(tv.size() / 2);
			ans.emplace_back(0, sum);
		}
		else if (tv.size() % 4 == 1) {
			int sum = tv[tv.size() / 2];
			for (int i = tv.size() / 2 + 1; i < tv.size(); ++i) {
				sum += tv[i];
				sv.push_back(tv[i]);
			}
			tv.resize(tv.size() / 2);
			ans.emplace_back(0, sum);
		}
		else if (tv.size() % 4 == 2) {
			int sum = 0;
			for (int i = tv.size() / 2; i < tv.size(); ++i) {
				sum += tv[i];
				sv.push_back(tv[i]);
			}
			tv.resize(tv.size() / 2);
			ans.emplace_back(0, sum);
		}
		else {
			int sum = 0;
			for (int i = tv.size() / 2; i < tv.size(); ++i) {
				sum += tv[i];
				sv.push_back(tv[i]);
			}
			tv.resize(tv.size() / 2);
			ans.emplace_back(0, sum);
		}
	}
	while (!sv.empty() && !tv.empty()) {
		if (sv.size() == 1) {
			if (tv.size() == 1) {
				ans.emplace_back(sv.back(), tv.back());
				sv.pop_back();
				tv.pop_back();
				continue;
			}
			if (tv.size() % 2 == 0) { 
				ans.emplace_back(sv.back(), tv.back() + tv[tv.size() - 2]);
				if (tv.size() > 2)
					tv[tv.size() - 3] += sv.back();
				sv.pop_back();
				sv.push_back(tv.back());
				tv.pop_back();
				tv.pop_back();
			}
			else {
				ans.emplace_back(sv.back(), tv.back() + tv[tv.size() - 2] + tv[tv.size() - 3]);
				if (tv.size() > 3)
					tv[tv.size() - 4] += sv.back();
				sv.pop_back();
				sv.push_back(tv[tv.size() - 2]);
				sv.push_back(tv.back());
				tv.pop_back();
				tv.pop_back();
				tv.pop_back();
			}
		}
		else if (tv.size() == 1) {
			if (sv.size() % 2 == 0) { 
				ans.emplace_back(sv.back() + sv[sv.size() - 2], tv.back());
				if (sv.size() > 2)
					sv[sv.size() - 3] += tv.back();
				tv.pop_back();
				tv.push_back(sv.back());
				sv.pop_back();
				sv.pop_back();
			}
			else {
				ans.emplace_back(sv.back() + sv[sv.size() - 2] + sv[sv.size() - 3], tv.back());
				if (sv.size() > 3)
					sv[sv.size() - 4] += tv.back();
				tv.pop_back();
				tv.push_back(sv[sv.size() - 2]);
				tv.push_back(sv.back());
				sv.pop_back();
				sv.pop_back();
				sv.pop_back();
			}
		}
		else if (sv.size() % 2 == tv.size() % 2) {
			ans.emplace_back(sv.back(), tv.back());
			tv[tv.size() - 2] += sv.back();
			sv[sv.size() - 2] += tv.back();
			sv.pop_back();
			tv.pop_back();
		}
		else {
			if (sv.size() <= tv.size()) {
				ans.emplace_back(sv.back(), tv.back() + tv[tv.size() - 2]);
				sv[sv.size() - 2] += tv[tv.size() - 2];
				tv[tv.size() - 3] += sv.back();
				sv.pop_back();
				sv.push_back(tv.back());
				tv.pop_back();
				tv.pop_back();
			}
			else {
				ans.emplace_back(sv.back() + sv[sv.size() - 2], tv.back());
				tv[tv.size() - 2] += sv[sv.size() - 2];
				sv[sv.size() - 3] += tv.back();
				tv.pop_back();
				tv.push_back(sv.back());
				sv.pop_back();
				sv.pop_back();
			}
		}
	}
	if (sv.empty()) {
		if (tv.size() == 1) {
			ans.emplace_back(0, tv.back());
		}
		else if (tv.size() == 2) {
			ans.emplace_back(0, tv.back() + tv[tv.size() - 2]);
			ans.emplace_back(tv.back(), 0);
		}
	}
	else {
		if (sv.size() == 1) {
			ans.emplace_back(sv.back(), 0);
		}
		else if (sv.size() == 2) {
			ans.emplace_back(sv.back() + sv[sv.size() - 2], 0);
			ans.emplace_back(0, sv.back());
		}
	}
	if (fl) {
		for (int i = 0; i < ans.size(); ++i)
			swap(ans[i].first, ans[i].second);
	}
	return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	string s, t;
	cin >> s >> t;
	auto vv = get(s, t);
	auto vv2 = get(t, s);
	if (vv2.size() < vv.size()) {
		vv = vv2;
		for (int i = 0; i < vv.size(); ++i)
			swap(vv[i].first, vv[i].second);
	}
	cout << vv.size() << "\n";
	for (auto e: vv) {
		cout << e.first << " " << e.second << "\n";
	}
	return 0;
}