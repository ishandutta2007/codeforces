#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define e1 first
#define e2 second
#define pb push_back
#define OUT(x) {cout << x << "\n"; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define sz(x) int(x.size())
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
/*#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
vector <mint> fac, inv;
mint binom(int n, int k) {
	if (n < k || n < 0) return 0;
	return fac[n] * inv[k] * inv[n-k];
}

void prep(int N) {
	fac.resize(N+1, 1); inv.resize(N+1, 1);
	for (int i=1; i<=N; ++i) fac[i] = fac[i-1] * i;
	inv[N] = fac[N].inv();
	for (int i=N-1; i>0; --i) inv[i] = inv[i+1] * (i + 1);
}*/

mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
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
const int maxn = 1000100;

//Did you REAALLY consider sample tests?

const int MAX = 53;
int conv(char c) {
	if (c == '$') return 0;
	if (c >= 'a' && c <= 'z') return c-'a'+1;
	if (c >= 'A' && c <= 'Z') return c-'A'+27;
	return 0;
}

char odwr(int x) {
	if (x == 0) return '$';
	else if (x >= 1 && x <= 26) return 'a'+x-1;
	else if (x >= 27) return 'A'+x-27;
}

int pos[11][MAX][2];
vector <pair<int, int> > vec;

int dp[MAX][1<<10];
pii ost[MAX][1<<10];
vi stan[MAX][1<<10];
string s[20];

void solve(int tc) {
	int n;
	cin >> n;
	vec.clear();
	rep(i, 0, 11) rep(j, 0, MAX) {
		pos[i][j][0] = pos[i][j][1] = -1;
	}
	rep(i, 0, MAX) rep(j, 0, 1<<10) {
		dp[i][j] = 0;
		stan[i][j].clear();
		ost[i][j] = {-1, -1};
	}
	
	rep(i, 0, n) {
		cin >> s[i];
		rep(j, 0, sz(s[i])) {
			int co = conv(s[i][j]);
			debug(i, j, co);
			if (pos[i][co][0] == -1) pos[i][co][0] = j;
			else pos[i][co][1] = j;
		}
	}
	
	rep(i, 0, n) {
		rep(j, 0, MAX) {
			if (pos[i][j][0] != -1) debug(pos[i][j][0], pos[i][j][1]);
		}
	}
	
	rep(znak, 0, MAX) {
		rep(mask, 0, 1<<n) {
			stan[znak][mask].clear();
			vi zbior;
			bool ok = true;
			rep(i, 0, n) {
				bool jest = (mask & (1 << i));
				if (pos[i][znak][jest] == -1) ok = false;
				else zbior.pb(pos[i][znak][jest]);
			}
			if (!ok) zbior.clear();
			stan[znak][mask] = zbior;
			if (!stan[znak][mask].empty()) vec.pb({znak, mask});
		}
	}
	
	sort(all(vec), [&](const pii&jed, const pii &dwa) -> bool {
		return stan[jed.e1][jed.e2] < stan[dwa.e1][dwa.e2];
	});
	
	pii best = {-1, -1};
	int opt = 0;
	
	for (auto &[znak, mask] : vec) {
		dp[znak][mask]++;
		if (dp[znak][mask] > opt) {
			opt = dp[znak][mask];
			best = {znak, mask};
		}
		
		for (int nchar = 0; nchar < MAX; ++nchar) {
			int newmask = 0;
			bool possible = 1;
			for (int i = 0; i < n; ++i) {
				bool bit = (mask & (1 << i));
				int gdzie = pos[i][znak][bit];
				assert(gdzie != -1);
				if (pos[i][nchar][0] != -1 && pos[i][nchar][0] > gdzie) newmask |= (0 << i);
				else if(pos[i][nchar][1] != -1 && pos[i][nchar][1] > gdzie) newmask |= (1 << i);
				else possible = 0;
			}
			
			if (possible) {
				if (dp[nchar][newmask] < dp[znak][mask]) {
					ost[nchar][newmask] = {znak, mask};
					dp[nchar][newmask] = dp[znak][mask];
				}
			}
		}
	}
	
	cout << opt << endl;
	string odp = "";
	while (opt > 0) {
		odp += (char)odwr(best.e1);
		--opt;
		if (opt > 0) best = ost[best.e1][best.e2];
	}
	reverse(all(odp));
	cout << odp << "\n";
}


int main() {
	boost;
	int tests;
	cin >> tests;
	//tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}