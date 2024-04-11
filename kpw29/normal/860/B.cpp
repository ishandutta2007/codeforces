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


void solve(int tc) {
	int n;
	cin >> n;
	vector <string> s(n);
	vector <string> ans(n);
	map <string, pii> cnt;
	
	rep(i, 0, n) {
		cin >> s[i];
		ans[i] = s[i];
	}
	
	rep(i, 0, n) {
		rep(pocz, 0, 9) {
			string ret = "";
			rep(kon, pocz, 9) {
				ret += s[i][kon];
				auto it = cnt.find(ret);
				if (it == cnt.end()) {
					cnt[ret] = {i, i};
				}
				else {
					cnt[ret] = {min(it->e2.e1, i), max(it->e2.e2, i)};
				}
			}
		}
	}
	
	rep(i, 0, n) {
		rep(pocz, 0, 9) {
			string ret = "";
			rep(kon, pocz, 9) {
				ret += s[i][kon];
				auto it = cnt.find(ret);
				assert(it != cnt.end());
				if (it->e2.e1 == i && it->e2.e2 == i) {
					if (sz(it->e1) < sz(ans[i])) ans[i] = it->e1;
				}
			}
		}
	}
	
	rep(i, 0, n) {
		string g = ans[i];
		cout << g << "\n";
	}
	

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