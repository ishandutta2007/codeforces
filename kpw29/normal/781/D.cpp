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
//#include <atcoder/modint>
//using namespace atcoder;
//using mint = modint1000000007;
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
const int maxn = 502;

bool dp[61][maxn][maxn];
bool rdp[61][maxn][maxn];

int n, m;

bitset <maxn> fromdp[maxn];
bitset <maxn> todp[maxn];

bitset <maxn> fromrdp[maxn];
bitset <maxn> tordp[maxn];

void solve(int tc) {
	//Did you REAALLY consider sample tests?
	cin >> n >> m;
	FOR(edge, 1, m) {
		int a, b;
		cin >> a >> b;
		int type;
		cin >> type;
		
		if (type == 0) dp[0][a][b] = 1;
		else rdp[0][a][b] = 1;
	}
	
	for (int step = 1; step <= 60; ++step) {
		FOR(i, 1, n) {
			fromdp[i].reset(); todp[i].reset();
			fromrdp[i].reset(); tordp[i].reset();
		}
		
		FOR(i, 1, n) {
			FOR(j, 1, n) {
				if (dp[step-1][i][j]) {
					fromdp[i].set(j, 1);
					todp[j].set(i, 1);
				}
				if (rdp[step-1][i][j]) {
					fromrdp[i].set(j, 1);
					tordp[j].set(i, 1);
				}
			}
		}
		
		FOR(i, 1, n) {
			FOR(j, 1, n) {
				dp[step][i][j] = (fromdp[i] & tordp[j]).any();
				rdp[step][i][j] = (fromrdp[i] & todp[j]).any();
				if (dp[step][i][j] || rdp[step][i][j]) {
					debug(step, i, j);
				}
				
			}
		}
	}
	
	FOR(i, 1, n) {
		if (dp[60][1][i]) OUT(-1);
	}
	
	// restore positive answer
	int bit = 0;
	vi used(n + 1, 0);
	used[1] = 1;
	
	ll wyn = 0;
	for (int step = 60; step >= 0; --step) {
		vi nused(n + 1, 0);
		
		FOR(i, 1, n) {
			if (!used[i]) continue;
			FOR(j, 1, n) {
				if (!bit && dp[step][i][j]) nused[j] = 1;
				if (bit && rdp[step][i][j]) nused[j] = 1;
			}
		}
		
		bool flag = 0;
		FOR(i, 1, n) {
			if (nused[i]) flag = 1;
		}
		
		if (flag) {
			bit ^= 1;
			wyn += (1LL << step);
			used = nused;
		}
	}
	
	ll INF = 1e18;
	if (wyn > INF) OUT("-1");
	cout << wyn << endl;
}

int main() {
	boost;
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}