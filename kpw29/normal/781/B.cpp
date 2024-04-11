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
const int maxn = 1010;

string A[maxn], B[maxn];
int n;

void solve(int tc) {
	//Did you REAALLY consider sample tests?
	cin >> n;
	FOR(i, 1, n) {
		cin >> A[i] >> B[i];
	}
	vector<string> ans(n + 1);
	
	rep(c1, 0, 26)
	rep(c2, 0, 26) {
		vi poz;
		vi pie;
		vi dru;
		
		FOR(i, 1, n) {
			if (A[i][0] == c1 + 'A' && A[i][1] == c2 + 'A') {
				poz.pb(i);
				pie.pb(A[i][2]-'A');
				dru.pb(B[i][0]-'A');
			}
		}
		if (poz.empty()) continue;
		debug(poz);
		debug(pie);
		debug(dru);
		
		if (sz(poz) > 26) OUT("NO");
		vi matched(sz(poz), -1);
		vi jest(26, 0);
		vector <vi> groups(26);
		int s = sz(poz);
		// i-ty w wektorze
		rep(i, 0, s) {
			groups[pie[i]].pb(i);
		}
		
		rep(g, 0, 26) {
			if (sz(groups[g]) > 1) {
				trav(i, groups[g]) {
					if (jest[dru[i]]) OUT("NO");
					matched[i] = dru[i]; //pierwszego nie mozna
					jest[dru[i]] = 1;
				}
			}
		}
		
		FOR(step, 0, 26) {
			rep(g, 0, 26) {
				if (sz(groups[g]) == 1) {
					int i = groups[g][0];
					if (matched[i] != -1) continue;
					if (jest[dru[i]] && jest[pie[i]]) OUT("NO");
					if (jest[dru[i]]) {
						matched[i] = pie[i];
						jest[pie[i]] = 1;
					}
					else if (jest[pie[i]]) {
						matched[i] = dru[i];
						jest[dru[i]] = 1;
					}
				}
			}
		}
		rep(g, 0, 26) {
			if (sz(groups[g]) == 1) {
				int i = groups[g][0];
				if (matched[i] != -1) continue;
				matched[i] = pie[i];
				jest[pie[i]] = 1;
			}
		}
		
		rep(i, 0, s) {
			string odp;
			odp += char(c1 + 'A');
			odp += char(c2 + 'A');
			odp += char(matched[i] + 'A');
			ans[poz[i]] = odp;
		}
	}
	
	set <string> odp;
	FOR(i, 1, n) odp.insert(ans[i]);
	assert(sz(odp) == n);
	cout << "YES\n";
	FOR(i, 1, n) cout << ans[i] << "\n";
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