#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin() ,(x).end()
#define st first
#define nd second
using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pll = pair<ll, ll>;

template <typename TH> void _dbg(const char *s, TH h) {
	cerr << s << "=" << h << "\n";
}
template <typename TH, typename ...TA> void _dbg(const char *s, TH h, TA... a) {
	while (*s != ',') cerr << *s++;
	cerr << "=" << h << ",";
	_dbg(s+1, a...);
}

template <typename T> ostream &operator<<(ostream &os, vector<T> V) {
	os <<"[";
	for (auto v:V) os << v << ",";
	return os << "]";
}
template <typename L, typename R> ostream &operator<<(ostream &os, pair<L,R> V) {
	return os << "(" << V.st << "," << V.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int kMaxN = 3e5;

int n;
ll mstart[kMaxN], mend[kMaxN], kintv[kMaxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> mstart[i] >> mend[i] >> kintv[i];
	}

	vector<pll> first_prods(n);
	for (int i = 0; i < n; ++i) {
		first_prods[i] = pll{mstart[i] + kintv[i], i};
	}
	first_prods.emplace_back(5e18, -1);

	sort(ALL(first_prods));
	set<tuple<ll, ll, ll>> avail_masters;
	int fprod_ptr = 0;

	ll ans = 0;
	ll tm = 0;
	while (true) {
		const ll next_start = first_prods[fprod_ptr].st;
		bool done = false;
		while (!avail_masters.empty()) {
			auto [intv, tmp, idx] = *avail_masters.begin();
			(void)tmp;
			if (mend[idx] < tm + intv) {
				avail_masters.erase(avail_masters.begin());
				continue;
			}
			
			ll max_intv = min({next_start, mend[idx]});
			const ll num_prod = (max_intv - max(tm, mstart[idx])) / intv;
			if (num_prod == 0) {
				break;
			}

			ans += num_prod;
			tm = max(tm, mstart[idx]) + intv * num_prod;
			done = true;
			break;
		}

		if (done) { continue; }
		if (fprod_ptr == n) { break; }

		const int who = first_prods[fprod_ptr++].nd;
		avail_masters.emplace(kintv[who], mstart[who], who);
	}

	cout << ans << "\n";
}