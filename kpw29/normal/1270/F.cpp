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
#include <bits/extc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//Did you REAALLY consider sample tests?
void solve(int tc) {
	string s;
	cin >> s;
	ll score = 0;
	
	int n = sz(s);
	vi pref(n+1);
	rep(i, 0, n) {
		pref[i+1] = pref[i] + s[i] - '0';
	}
	
	//i % 2 -> taki jest znak
	vi grupa = {0};
	ll cnt = 0;
	rep(i, 0, n) {
		if (s[i] == '1') ++cnt;
		else cnt = 0;
		score += cnt;
	}
	
	rep(i, 0, n) {
		if (s[i] == '1') {
			if (sz(grupa) % 2 == 1) grupa.pb(1);
			else {
				grupa.pb(0); grupa.pb(1);
			}
		}
		else {
			if (sz(grupa) % 2 == 1) grupa[sz(grupa)-1]++;
			else grupa.pb(1);
		}
	}
	
	if (s.back() == '1') grupa.pb(0);
	
	vi prefgrupa(sz(grupa) + 1);
	rep(i, 1, sz(prefgrupa)) {
		if (i % 2 == 1) prefgrupa[i] = prefgrupa[i-1] + grupa[i-1];
		else prefgrupa[i] = prefgrupa[i-1];
	}
	
	auto gsum = [&](int a, int b) ->int{
		debug("Query", a, b);
		return prefgrupa[b + 1] - prefgrupa[a];
	};
	
	debug(grupa);
	debug(score);
	
	int ss = min(n, 200);
	for (int k=1; k<=ss; ++k) {
		ll tmp = 0;
		unordered_map<int, int> M;
		M.max_load_factor(0.25);
		M.reserve(2048);
		M[0]++;
		
		FOR(i, 1, n) {
			int jed = pref[i], zer = i - pref[i];
			tmp += M[zer - k * jed];
			M[zer - k * jed]++;
		}
		
		debug(k, tmp);
		score += tmp;
	}
	
	debug(score);
	for (int end = 1; end < sz(grupa); end += 2) {
		int pocz = end;
		while (true) {
			int ile_jest = (end-pocz)/2+1;
			if (ile_jest * (ss + 1) > n) break;
			if (pocz < 1) break;
			int k = ile_jest;
			
			for (int lewo = 0; lewo <= grupa[pocz - 1]; ++lewo) { //biore
				int mamzer = gsum(pocz, end) + lewo;
				int mamjed = ile_jest;
				int dostepne = grupa[end + 1];
				int minimum = (ss + 1) * mamjed;
				if (mamzer < minimum) {
					dostepne -= (minimum - mamzer);
					if (dostepne < 0) continue;
					mamzer = minimum;
				}
				debug(pocz, end);
				debug(mamzer, mamjed, lewo, dostepne);
				if (mamzer % k != 0) {
					int teraz = (mamzer % k);
					int musze_dodac = k - teraz;
					dostepne -= musze_dodac;
					if (dostepne < 0) continue;
					mamzer += musze_dodac;
				}
				if (dostepne < 0) continue;
				score += 1 + (dostepne / k);
			}
			
			pocz -= 2;
		}
	}
	
	cout << score << "\n";
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