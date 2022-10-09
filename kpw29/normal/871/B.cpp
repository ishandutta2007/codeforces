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
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#endif

#ifdef DEBUG
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif

bool LOCAL = 0;

vi p;
vi b;

int ask(int i, int j) {
	cout << "? " << i << ' ' << j << endl;
	if (LOCAL) {
		return (p[i] ^ b[j]);
	}
	else {
		int odp;
		cin >> odp;
		return odp;
	}
}

void solve(int tc) {
	int n;
	cin >> n;
	
	if (LOCAL) {
		p.resize(n, 0);
		b.resize(n, 0);
		rep(i, 0, n) {
			cin >> p[i];
			b[p[i]] = i;
		}
		
		debug(p);
		debug(b);
	}
	
	vi queries(n, 0);
	rep(i, 0, n) queries[i] = ask(i, 0);
	debug(queries);
	
	vi help(n, 0);
	rep(i, 0, n) help[i] = ask(0, i);
	
	vi wynik;
	int ile = 0;
	auto probuj =[&](int st) {
		vi odw(2 * n, 0);
		vi tmp(n, 0);
		tmp[0] = st;
		odw[st] = 1;
		
		rep(i, 1, n) {
			tmp[i] = tmp[0] ^ (queries[0] ^ queries[i]);
			if (tmp[i] >= n || odw[tmp[i]]) return 0;
			odw[tmp[i]] = 1;
		}
		debug(tmp);
		
		odw.clear();
		odw.resize(n, 0);
		vi bi(n, 0);
		rep(i, 0, n) bi[tmp[i]] = i;
		
		if ((bi[0] ^ tmp[0]) != queries[0]) return 0;
		rep(i, 0, n) {
			if (help[i] != (tmp[0] ^ bi[i])) return 0;
		}
		
		debug(b);
		debug(tmp);
		
		wynik = tmp;
		return 1;
	};
	
	rep(i, 0, n) ile += probuj(i);
	
	cout << "!\n";
	cout << ile << "\n";
	trav(u, wynik) cout << u << ' ';
	cout << endl;
			
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