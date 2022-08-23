//#ifndef BZ
#pragma GCC optimize "-O3"
//#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

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

const int MAXN = 120000;
const int SQ = 500;
const ll MOD = 998244353;

vector<int> gg[MAXN];
int a[MAXN];
int pl[MAXN];

int n, k;
int lst[MAXN];

int ad[MAXN];
pair<int, int> bb[MAXN];
ll dp[MAXN];
ll sm[MAXN];

void add(ll &a, ll b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
}

void add(int l, int r, int d) {
	for (int i = 0; i * SQ < r; ++i) {
		int lb = i * SQ;
		int rb = min(n, (i + 1) * SQ);
		if (l <= lb && rb <= r)
			ad[i] += d;
		else if (rb <= l)
			continue;
		else {
			for (int j = lb; j < rb; ++j)
				if (bb[j].second >= l && bb[j].second < r)
					bb[j].first += d;
			sort(bb + lb, bb + rb);
			ll now = 0;
			for (int j = lb; j < rb; ++j)
				add(now, dp[bb[j].second]), sm[j] = now;
		}
	}
}


void upd(int x) {
	int b = x / SQ;
	int lb = b * SQ;
	int rb = min(n, (b + 1) * SQ);
	ll now = 0;
	for (int j = lb; j < rb; ++j)
		add(now, dp[bb[j].second]), sm[j] = now;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i], pl[i] = gg[a[i]].size(), gg[a[i]].push_back(i);
	}
	for (int i = 0; i < n; ++i)
		bb[i] = make_pair(0, i);
	
	dp[0] = 1;
	upd(0);
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		int pr = -1;
		if (pl[i] != 0)
			pr = gg[x][pl[i] - 1];
		lst[i] = pr;
		add(pr + 1, i + 1, 1);
		if (pr != -1)
			add(lst[pr] + 1, pr + 1, -1);
		ll ans = 0;
		for (int j = 0; j * SQ <= i; ++j) {
			int x = lower_bound(bb + j * SQ, bb + min(n, (j + 1) * SQ), make_pair(k + 1 - ad[j], 0)) - bb;
			--x;
			if (x >= j * SQ)
				add(ans, sm[x]);
		}
		dp[i + 1] = ans;
		upd(i + 1);
	}
	cout << dp[n] << "\n";
	return 0;
}