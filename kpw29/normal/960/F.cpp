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
const int maxn = 100010;
set <pii> q[maxn];
int n, m;
int a, b, w;

int query(int weight) {
	if (q[a].empty()) return 0;
	auto it = q[a].lower_bound({weight, -1});
	if (it == q[a].begin()) return 0;
	--it;
	return it->e2;
}
void upd(int weight, int opt) {
	vector <set<pii>::iterator > toerase;
	auto it = q[b].lower_bound({weight, -1});
	while (it != q[b].end() && (it->e2 <= opt)) {
		toerase.pb(it);		
		++it;
	}
	trav(cos, toerase) {
		debug("Erasing", cos->e1, cos->e2);
		q[b].erase(cos);
	}
	
	q[b].insert({weight, opt});
	toerase.clear();
	toerase.shrink_to_fit();
};

void solve(int tc) {
    srand(2137);
	//Did you REAALLY consider sample tests?
	cin >> n >> m;
	//n = 10000; m = 100000;
	int tot = 0;
	FOR(i, 1, m) {
		debug(i);
		//FOR(j, 1, n) debug(q[j]);
		cin >> a >> b >> w;
		++w;
		//a = rand()%n+1; b = rand()%n+1; w = rand()%100;
		int score = query(w) + 1;
		tot = max(score, tot);
		auto it = q[b].lower_bound({w, -1});
		bool flag = false;
		
		if (it != q[b].begin()) {
			--it;
			if (it->e2 >= score) flag = true;
		}

		if (!flag) upd(w, score);
	}
	
	cout << tot << "\n";
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