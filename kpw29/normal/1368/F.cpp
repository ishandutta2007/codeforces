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
int is_square(int x) {
	int s = sqrt(x);
	while (s * s < x) ++s;
	return s * s == x;
}

int sufit(int n, int k) {
	if (n % k == 0) return n / k;
	return 1 + n / k;
}

bool TEST = 0;
void solve(int tc) {
	int n;
	cin >> n;
	int initn = n;
	if (n <= 3) {
		cout << 0 << endl;
		exit(0);
	}
	while (!is_square(n)) --n;
	int k = sqrt(n);
	while (k * k < n) ++k;
	assert(k * k == n);
	
	vi vec(initn, 0);
	
	vi zgasil;
	auto opponent = [&](int start) {
		zgasil.clear();
		start--;
		for (int i=0; i<k; ++i) {
			int dest = (i + start) % initn;
			if (vec[dest] == 1) zgasil.pb(dest);
			vec[dest] = 0;
		}
	};
	
	auto play = [&](vi zbior) -> int {
		trav(u, zbior) vec[u] = 1;
		cout << sz(zbior) << ' ';
		trav(u, zbior) cout << u + 1 << ' ';
		cout << endl;
		
		int ans = 0;
		if (!TEST) cin >> ans;
		
		opponent(ans);
		assert(ans != -1);
		return ans;
	};
	
	int ile_blokow = sufit(initn, k);
	vi ruch = {};
	rep(i, 0, k) ruch.pb(k * i);
	play(ruch);
	
	vi capacity(ile_blokow, 0);
	rep(i, 0, initn) capacity[i / k]++;
	
	while (true) {
		ruch.clear();
		trav(u, zgasil) {
			ruch.pb(u); //dodam to do ruchu
			vec[u] = 1;
		}
		vi ile(ile_blokow, 0);
		rep(i, 0, initn) {
			ile[i / k] += vec[i];
		}
		vi dodam(ile_blokow, 0);
		
		bool nowych = true;
		while (sz(ruch) < k) {
			nowych = false;
			rep(i, 0, ile_blokow) {
				if (sz(ruch) < k && ile[i] + dodam[i] + 1 != capacity[i]) {
					nowych = true;
					int j = k * i;
					while (vec[j] == 1) ++j;
					vec[j] = 1;
					ruch.pb(j);
					++dodam[i];
				}
			}
			
			if (!nowych) break;
		}
		
		if (!nowych) {
			cout << 0 << endl;
			exit(0);
		}
		else {
			play(ruch);
		}
	};
	
}

int main() {
	solve(0);
}