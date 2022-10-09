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


const int maxn = 100100;
int pr[maxn];
int first_left[maxn];
int A[maxn], B[maxn];
vector <int> que[maxn];
int a[maxn];
int ans[maxn];
int occ[maxn];

int skok[18][maxn];

vector <int> primes(int x) {
	vector <int> ret = {};
	while (x != 1) {
		int dz = pr[x];
		ret.pb(dz);
		while (x % dz == 0) x /= dz;
	}
	
	return ret;
}

void solveone() {
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, m) {
		cin >> A[i] >> B[i];
		que[B[i]].pb(i);
	}
	
	FOR(j, 0, 17) skok[j][0] = 0;
	
	FOR(i, 1, n) {
		auto prim = primes(a[i]);
		first_left[i] = 1;
		for (auto u : prim) {
			first_left[i] = max(first_left[i], occ[u] + 1);
			occ[u] = i;
		}
		
		if (i > 1) first_left[i] = max(first_left[i], first_left[i-1]);
		
		skok[0][i] = first_left[i];
		for (int j = 1; j < 18; ++j) {
			int gdzie = skok[j-1][i];
			skok[j][i] = skok[j-1][gdzie - 1];
		}
	
		for (auto qi : que[i]) {
			int aa = A[qi], covered = B[qi] + 1;
			int answer = 0;
			
			for (int j = 17; j >= 0; --j) {
				int gdzie = skok[j][covered - 1];
				if (gdzie >= aa) {
					answer += (1 << j);
					covered = gdzie;
				}
			}
			
			if (covered > aa) ++answer;
			ans[qi] = answer;
		}
	}
	
	
	FOR(i, 1, m) cout << ans[i] << "\n";
}

int main() {
	FOR(i, 1, 100000) pr[i] = i;
	FOR(i, 2, 100000) {
		if (pr[i] == i) {
			for (int j=i; j<maxn; j+=i) pr[j] = min(pr[j], i);
		}
	}
	
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) {
		solveone();
	}
}