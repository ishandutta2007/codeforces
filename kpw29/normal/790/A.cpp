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

string name(int value) {
	string ret = "X";
	if (value < 26) ret += (char)(value + 'a');
	else {
		ret += 'a';
		ret += (char)(value - 26 + 'a');
	}
	return ret;
}

void solve(int tc) {
	//NO RUSH, READ SAMPLES
	int n, k;
	cin >> n >> k;
	vi tab(n+1, 0);
	FOR(i, 1, n-k+1) {
		string s;
		cin >> s;
		//s = "YES";
		if (s == "NO") tab[i] = 1;
		else tab[i] = 0;
	}
	
	vi val(n+1, 0);
	FOR(i, 1, k-1) val[i] = i;
	int base = k - 1;
	int OLD = k -1;
	FOR(i, 1, n-k+1) {
		if (tab[i]) val[i+base] = val[i+base-(k-1)];
		else val[i+base] = ++OLD;
	}
	trav(node, val) cerr << node << ' ';
	cerr << endl;
	
	FOR(i, 1, n) cout << name(val[i]) << ' ';
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