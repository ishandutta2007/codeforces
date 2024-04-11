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
typedef pair <PLL, PLL > PP;
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
const int maxn = 300100;

vector <int> ch[maxn], v[maxn];
vector <ll> pref, suf;
ll chosen[maxn], cut[maxn], impossible[maxn];
int n;

void dfs(int x, int par = 1) {
	chosen[x] = 1;
	ll allcut = 1;
	for (auto u : v[x])
		if (u != par) {
			ch[x].pb(u);
			dfs(u, x);
			chosen[x] = (chosen[x] * (cut[u] + impossible[u])) % mod;
			allcut = allcut * cut[u] % mod;
		}
	
	if (ch[x].empty()) {
		impossible[x] = 0;
		cut[x] = 1;
		chosen[x] = 1;
		return;
	}
	
	int sz = ch[x].size();
	pref.resize(sz);
	suf.resize(sz);
	ll pf = 1;
	for (int i=0; i<sz; ++i) {
		pf = pf * (cut[ch[x][i]] + impossible[ch[x][i]]) % mod;
		pref[i] = pf;
	}
	
	ll sf = 1;
	for (int i=sz-1; i>=0; --i) {
		sf = sf * (cut[ch[x][i]] + impossible[ch[x][i]]) % mod;
		suf[i] = sf;
	}
	
	ll sum_choices = 0;
	for (int i=0; i<sz; ++i) {
		ll tmp_choice = chosen[ch[x][i]];
		if (i > 0) tmp_choice = tmp_choice * pref[i - 1] % mod;
		if (i + 1 != sz) tmp_choice = tmp_choice * suf[i + 1] % mod;
		sum_choices += tmp_choice;
	}
	
	sum_choices %= mod;
	cut[x] = (sum_choices + allcut) % mod;
	impossible[x] = sum_choices;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=1; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	dfs(1);
	cout << cut[1];
}