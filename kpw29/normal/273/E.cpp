#include <bits/stdc++.h>
#include <time.h>
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
const int mod = 1e9+7;
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

int nim[100100], N = 100000;
int jest[3];

int tab[1010][1010];

vector <PII> res;
vector <int> vals;

inline int getNim(int value, int curr_expanding) {
	if (value > res.back().e2) return curr_expanding;
	int x = 0, y = res.size() - 1;
	while (x < y) {
		int sr = (x + y) / 2;
		if (res[sr].e1 <= value && value <= res[sr].e2) return vals[sr];
		if (value < res[sr].e1) y = --sr;
		else x = ++sr;
	}
	
	return vals[x];
}

inline int findNim(int length, int curr_expanding) {
	FOR(j, 0, 2) jest[j] = false;
	int val = length / 3;
	jest[getNim(length - val, curr_expanding)] = true;
	jest[getNim(val, curr_expanding)] = true;
		
	int nm = 0;
	while (jest[nm]) ++nm;
	return nm;
}

const int MAXP = 1000;

void expand() {
	int next_point = res.back().e2 + 1;
	int curr_value = findNim(next_point, 0);
	int gn = -1;
	for (int pt = 1; next_point + pt - 1 <= (int)1e9; pt *= 2) {
		int query_point = next_point + pt - 1;
		int value = findNim(query_point, curr_value);
		if (value != curr_value) {
			gn = query_point;
			break;
		}
	}
	
	
	if (gn == -1) {
		res.push_back({next_point, (int)1e9});
		vals.pb(curr_value);
		return;
	}
	
	//there is some next interval
	int binx = next_point, biny = gn;
	while (binx < biny) {
		int sr = (binx + biny) / 2 + 1;
		if (findNim(sr, curr_value) != curr_value) biny = --sr;
		else binx = sr;
	}
	
	res.push_back({next_point, binx});
	vals.pb(curr_value);
	return;
}

ll ways[4];
ll dp[1010][4];
int n, p;

int main() {
	nim[0] = nim[1] = nim[2] = 0;
	for (int i=3; i<=N; ++i) {
		int val = (i / 3);
		FOR(j, 0, 2) jest[j] = false;
		
		jest[nim[i - val]] = true;
		jest[nim[val]] = true;
		
		int nm = 0;
		while (jest[nm]) ++nm;
		nim[i] = nm;
	}
	
	//debug(i, nim[i]);
	
	
	/*for (int len=0; len<=N; ++len)
		for (int i=0; i+len<=N; ++i){
			int j = i + len;
			FOR(k, 0, 2) jest[k] = false;
			if (j - i <= 2) tab[i][j] = 0;
			else {
				int ln = (j - i) / 3;
				jest[tab[i + ln][i + 2 * ln]] = true;
				jest[tab[i][j - ln]] = true;
				
				int nm = 0;
				while (jest[nm]) ++nm;
				tab[i][j] = nm;
			}
		}
		
	FOR(i, 0, 20) {
		FOR(j, 0, 20) cout << tab[i][j] << ' ';
		cout << endl;
	}*/
	
	res = {};
	vector <int> lengths = {};
	vals = {};
	
	int pos = 0;
	FOR(i, 1, N) {
		if (nim[pos] != nim[i]) {
			res.pb({pos, i - 1});
			vals.pb(nim[pos]);
			lengths.pb(res.back().e2 - res.back().e1 + 1);
			pos = i;
		}
	}
	
	res.pop_back();
	res.pop_back();
	vals.pop_back();
	vals.pop_back();
	
	int tr = 0;
	while (res.back().e2 != (int)1e9) {
		expand();
		/*debug(res);
		debug("\n");
		++tr;
		
		if (tr == 10) break;*/
	}
	
	/*int sz = res.size();
	for (int i=0; i<sz; ++i) debug(res[i], vals[i]);*/
	res[0].e1++;
	
	cin >> n >> p;
	if (p == 1) OUT(0);
	--p;
	
	int sz = res.size();
	for (int i=0; i<sz; ++i) {
		PII u = res[i];
		if (p < u.e1) break;
		
		int max_val = min(p, u.e2), min_val = u.e1;
		ll leng = max_val - min_val + 1;
		ll pocz = (p - min_val + 1), kon = (p - max_val + 1);
		ll val = (leng * (pocz + kon)) / 2;
		ways[vals[i]] += val % mod;
	}
	
	FOR(i, 0, 3) ways[i] %= mod;
	
	//FOR(i, 0, 3) cout << ways[i] << ' ';
	//cout << endl;
	
	
	dp[0][0] = 1;
	for (int i=1; i<=n; ++i) {
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k <= 2; ++k) {
				dp[i][(j ^ k)] += dp[i-1][j] * ways[k];
				dp[i][(j ^ k)] %= mod;
			}
	}
	
	ll solve = 0;
	FOR(i, 1, 3) solve += dp[n][i];
	solve %= mod;
	cout << solve;
}