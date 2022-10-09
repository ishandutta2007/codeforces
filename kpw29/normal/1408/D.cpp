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

const int maxn = 1000100;

int n, m, k;
int X[4010], Y[4010];
int res[maxn];

vector <PII> v;
vector <PII> stos;

void solveone() {
	cin >> n >> m;
	FOR(i, 1, n) cin >> X[i] >> Y[i];
	FOR(i, 1, m) cin >> X[n+i] >> Y[n+i];
	
	FOR(i, 1, n)
		FOR(j, n + 1, n + m) {
			if (X[i] <= X[j] && Y[i] <= Y[j]) {
				v.push_back(make_pair(X[j] - X[i] + 1, Y[j] - Y[i] + 1));
			}
		}
	

	sort(v.begin(), v.end());
	if (v.empty()) {
		cout << "0\n";
		return;
	}
	//debug(v);
	
	stos.pb(v[0]);
	for (int i=1; i<(int)v.size(); ++i) {
		while (!stos.empty() && stos.back().e2 <= v[i].e2) stos.pop_back();
		stos.push_back(v[i]);
		//debug(stos);
	}

	
	int result = INT_MAX;
	for (int i=0; i+1<(int)stos.size(); ++i) {
		result = min(result, stos[i].e1 + stos[i + 1].e2);
	}
	
	result = min(result, stos[0].e2);
	result = min(result, stos.back().e1);
	cout << result << "\n";
}

int main() {
	cout << fixed << setprecision(15);
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}