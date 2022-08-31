#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

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
const int MAXN = 3100;

vector<pair<int, int> > vv;
int a[MAXN];
int cl[MAXN];
int n;

deque<pair<int, int> > dq;

void clear() {
	dq.clear();
}

void add(int x) {
	pair<int, int> now = {vv[x - 1].first - vv[x].first, x};
	while (!dq.empty() && dq.back().first <= now.first)
		dq.pop_back();
	dq.push_back(now);
}

void del(int x) {
	if (!dq.empty() && dq.front().second == x)
		dq.pop_front();
}

int main() {
#ifdef BZ
	freopen("in", "r", stdin);
#endif
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i], vv.emplace_back(a[i], i);
	sort(ALL(vv));
	reverse(ALL(vv));
	vv.emplace_back(0, -1);
	array<int, 6> ans = {0, 0, 0, 1, 1, 1};
	n += 1;
	for (int i = 1; i < n; ++i) {
		clear();
		int lb = i;
		int rb = i;
		for (int j = i + 1; j < n - 1; ++j) {
			int a = i;
			int b = j - i;
			if (max(a, b) > 2 * min(a, b))
				continue;
			int ml = max((a + 1) / 2, (b + 1) / 2);
			int mx = min(2 * a, 2 * b);
			while (lb < rb && lb - j < ml)
				del(lb), ++lb;
			if (lb == rb)
				lb = rb = j + ml;
			if (lb >= n)
				break;
			while (rb < n && rb - j <= mx)
				add(rb), ++rb;
			if (!dq.empty()) {
				auto x = dq.front();
				ans = max(ans, {vv[i - 1].first - vv[i].first, vv[j - 1].first - vv[j].first, x.first, i, j - i, x.second - j});
			}
		}
	}
	--n;
	for (int i = 0; i < n; ++i)
		cl[i] = -1;
	for (int i = 0; i < ans[3]; ++i)
		cl[vv[i].second] = 1;
	for (int i = ans[3]; i < ans[3] + ans[4]; ++i)
		cl[vv[i].second] = 2;
	for (int i = ans[3] + ans[4]; i < ans[3] + ans[4] + ans[5]; ++i)
		cl[vv[i].second] = 3;
	for (int i = 0; i < n; ++i)
		cout << cl[i] << " ";
	cout << "\n";
	return 0;
}