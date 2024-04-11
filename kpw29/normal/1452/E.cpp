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
const int mod = 998244353;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 4LL * 1000000LL * 1000000LL * 1000000LL;

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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}

const int maxn = 2010;
int pref_scores[maxn][maxn];
int suf_scores[maxn][maxn];
int pref_best[maxn], suf_best[maxn];
int A[maxn], B[maxn];

int n, m, k;
PII ivs[maxn];


int score(int pos, int iv_id) {
	PII i1 = make_pair(pos, pos + k - 1);
	PII i2 = make_pair(A[iv_id], B[iv_id]);
	
	int beg = max(i1.first, i2.first);
	int nd = min(i1.second, i2.second);
	return max(0, nd - beg + 1);
}

void solveone() {
	cin >> n >> m >> k;
	FOR(i, 1, m) {
		cin >> A[i] >> B[i];
		ivs[i] = mp((A[i] + B[i]) / 2, i);
	}
	
	sort(ivs+1, ivs+m+1);
	FOR(i, 1, m) {
		FOR(pos, 1, n-k+1) {
			pref_scores[i][pos] = pref_scores[i-1][pos] + score(pos, ivs[i].e2);
			pref_best[i] = max(pref_best[i], pref_scores[i][pos]);
		}
	} 
	
	for (int i=m; i>0; --i) {
		FOR(pos, 1, n-k+1) {
			suf_scores[i][pos] = suf_scores[i+1][pos] + score(pos, ivs[i].e2);
			suf_best[i] = max(suf_best[i], suf_scores[i][pos]);
		}
	}
	int res = 0;
	for (int i=0; i<m; ++i) res = max(res, pref_best[i] + suf_best[i+1]);
	cout << res << endl;
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}