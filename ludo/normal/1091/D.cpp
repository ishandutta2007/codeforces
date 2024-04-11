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

const ll MOD = 998244353;

ll powmod(ll b, ll e) {
	ll r = 1;
	for ( ; e; e /= 2, b = b*b%MOD) if (e &1)r=r*b%MOD;
	return r;
}

void run() {
	ll n;
	cin >> n;

	ll nfact = 1;
	REP(i, n) nfact = nfact*(i+1) % MOD;

	ll r = (1LL + nfact * n) % MOD;
	
	// (n!)^{-1}
	ll invs = 0;
	ll inv = powmod(nfact, MOD - 2);

	for (int i = n; i > 0; i--) {
		invs = (invs + inv) % MOD;
		inv = (inv * i) % MOD;
	}

	r = (r - nfact * invs) % MOD;
	if (r < 0) r += MOD;
	cout << r << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	run();
	return 0;
}