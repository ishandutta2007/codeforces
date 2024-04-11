#include <bits/stdc++.h>
using namespace std;

#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
#ifdef DEBUG
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == prev(x.end()) ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#endif
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(0);
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
const LL INF = 1e18;
const int maxn = 300100;
const int mod = 998244353;

void solve() {
	ll n, m;
	cin >> n >> m;
	vector <vector <ll> > arr(n, vector <ll>(m, 0));
	ll max_input = 0;
	
	vector <ll> A(n, -1);
	vector <ll> B(m, -1);
	
	FOR(i, 0, n-1) {
		FOR(j, 0, m-1) {
			cin >> arr[i][j];
			max_input = max(max_input, arr[i][j]);
		}
	}
	
	ll k = 0;
	A[0] = 0;
	FOR(i, 0, m-1) B[i] = arr[0][i];
	
	FOR(i, 1, n-1) {
		vector <ll> values;
		FOR(j, 0, m-1) values.pb(arr[i][j] - B[j]);
		sort(all(values));
		
		FOR(j, 1, m-1) k = __gcd(k, values[j] - values[j-1]);
	}
	
	if (k == 0) k = max_input + 1;
	if (k <= max_input) OUT("NO");
	FOR(i, 1, n-1){
		ll ma_byc = arr[i][0] - B[0];
		if (ma_byc < 0) ma_byc += inf * k;
		A[i] = ma_byc % k;
	}
	
	cout << "YES\n";
	cout << k << endl;
	FOR(i, 0, n-1) cout << A[i] % k << ' ';
	cout << endl;
	FOR(i, 0, m-1) cout << B[i] % k << ' ';
	cout << endl;
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	while (tests--) {
		solve();
	}
}