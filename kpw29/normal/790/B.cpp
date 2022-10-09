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
const int maxn = 200100;
ll sums[maxn][5];
ll ile[maxn][5];

vi v[maxn];
ll wyn;
int n, k;
ll tmps[5];
ll tmpi[5];

void dfs(int x, int par) {
	trav(u, v[x]) if (u != par){
		dfs(u, x);
		
		rep(i, 0, k) {
			rep(j, 0, k) {
				wyn += (sums[x][i] * ile[u][j] + sums[u][j] * ile[x][i]); //and now sum modulus
				int ss = (i + j);
				if (ss == 0) continue;
				if (ss <= k) { //something is missed 
					wyn += ile[x][i] * ile[u][j];
				}
				else { //twice!
					wyn += ile[x][i] * ile[u][j] * 2;
				}
			}
		}
		
		rep(i, 0, k) {
			sums[x][i] += sums[u][i];
			ile[x][i] += ile[u][i];
		}
	}
	
	rep(i, 0, k) {
		wyn += sums[x][i];
		if (i != 0) wyn += ile[x][i];
	}
	
	if (x != 1) {
		rep(i, 0, k) tmps[i] = tmpi[i] = 0;
		
		rep(i, 0, k) {
			tmpi[(i + 1) % k] += ile[x][i];
			if (i + 1 == k) tmps[0] += ile[x][i];
			tmps[(i + 1) % k] += sums[x][i];
		}
		
		rep(i, 0, k) sums[x][i] = tmps[i], ile[x][i] = tmpi[i];

		//add parent
		ile[x][1%k]++; 
		if (k <= 1) sums[x][1%k]++;
	}
	
	/*debug(x);
	debug("sums");
	rep(i, 0, k) cerr << sums[x][i] << ' ';
	cerr << endl;
	debug("ile");
	rep(i, 0, k) cerr << ile[x][i] << ' ';
	cerr << endl;*/
}

void solve(int tc) {
	cin >> n >> k;
	rep(i, 1, n) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 1);
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