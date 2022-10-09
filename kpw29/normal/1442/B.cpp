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

const int maxn = 200100;
int available[maxn], L[maxn], R[maxn];
int a[maxn], b[maxn];
int pos_ina[maxn];

void rem(int pos) {
	L[R[pos]] = L[pos];
	R[L[pos]] = R[pos];
}

void solveone() {
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> a[i];
		available[i] = 1;
		pos_ina[a[i]] = i;
	}
	
	available[0] = available[n + 1] = false;
	
	FOR(i, 1, n) R[i] = i + 1;
	FOR(i, 1, n) L[i] = i - 1;

	ll score = 1;
	FOR(i, 1, m) {
		cin >> b[i];
		available[pos_ina[b[i]]] = 0;
	}
	
	FOR(i, 1, m) {
		int value = b[i];
		int where_a = pos_ina[value];
		
		int pos_left = L[where_a], pos_right = R[where_a];
		if (!available[pos_left] && !available[pos_right]) {
			cout << "0\n";
			return;
		}
		
		if (available[pos_left] && available[pos_right]) score = (score * 2) % mod;
		if (available[pos_left]) rem(pos_left);
		else rem(pos_right);
		available[where_a] = 1; //now we can use this position too
	}
	
	cout << score << "\n";
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}