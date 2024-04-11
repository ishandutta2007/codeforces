#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 1e9 + 7;
const int maxn = 1e5;

int n, x, y;
int L[maxn], R[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x >> y;
	REP(i, n)
		cin >> L[i] >> R[i];
	
	int costanyway = 0;
	REP(i, n) {
		ll inc = x;
		inc += 1LL * y * (R[i] - L[i]);

		costanyway = costanyway + (int) (inc % mod);
		if (costanyway >= mod) costanyway -= mod;
	}

	// match closest ones first.
	vector<ii> events;
	REP(i, n) events.eb(L[i], 0);
	REP(i, n) events.eb(R[i], 1);

	// first lhs then rhs
	sort(all(events));

	vi unmat; // unmatched rhs
	int save = 0;
	for (ii evt : events) {
		if (evt.y == 1) {
			// rhs
			unmat.pb(evt.x);
		} else {
			// lhs
			if (unmat.empty()) continue;
			int lst = unmat.back();
			unmat.pop_back();

			ll possave = 1LL * x - 1LL * y * (evt.x - lst);
			if (possave > 0) {
				save += (int) (possave % mod);
				if (save >= mod) save -= mod;
			}
		}
	}

	ll ret = costanyway - save;
	ret = ((ret % mod) + mod) % mod;
	cout << ret << endl;
	return 0;
}