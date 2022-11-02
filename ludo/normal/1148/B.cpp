#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const int INF = 2147483647; // (1 << 30) - 1 + (1 << 30)
const ll LLINF = (1LL << 62) - 1 + (1LL << 62); // = 9.223.372.036.854.775.807
const double PI = acos(-1.0);

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int maxn = 2e5;
ll n, m, ta, tb, k;
ll A[maxn], B[maxn];

ll run() {
	cin >> n >> m >> ta >> tb >> k;

	REP(i, n) { cin >> A[i]; A[i] += ta; }
	REP(i, m) cin >> B[i];

	if (k >= n || k >= m) return -1;

	ll best = 0;
	for (int j = 0; j <= k; j++) {
		// if we take out the j first A's?
		// take out the first k-j B's after the first available A.
		ll landed = A[j];
		int idx = (lower_bound(B, B + m, landed) - B);
		idx += k-j;

		if (idx >= m) return -1;

		best = max(best, B[idx]);
	}
	return best + tb;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	ll ans = run();
	cout << ans << endl;
	return 0;
}