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

inline int get_lvl(ll x) {
	return 63-__builtin_clzll(x);
}

void solve(int tc) {
	//Did you REAALLY consider sample tests?
}

ll pie[62];
ll len[62];
ll ult[62];

ll MOD = (1LL << 62);

ll get_on_pos(ll pos, int lvl) {
	assert(1LL <= pos && pos <= len[lvl]);
	if (get_lvl(pie[lvl] + pos - 1) == lvl) return pie[lvl] + pos - 1;
	//else wyszlo za duzo, modulujemy
	return pie[lvl] + pos - 1 - len[lvl];
}

ll get_pos(ll value) {
	int lvl = get_lvl(value);
	if (value >= pie[lvl]) return value - pie[lvl] + 1;
	else {
		return (value + len[lvl] - pie[lvl] + 1);
	}
}

void shift(int lvl, ll k) {
	// trzeba odpowiednio zmodulowac k
	if (k < 0) k += MOD;
	k %= len[lvl];
	debug("Shifting", lvl, k);
	ll tmp = pie[lvl] - k;
	while (tmp < ult[lvl]) tmp += len[lvl];
	while (tmp >= ult[lvl + 1]) tmp -= len[lvl];
	pie[lvl] = tmp;
}

int main() {
	boost;
	pie[0] = 1;
	len[0] = 1;
	FOR(i, 1, 61) {
		pie[i] = pie[i-1] + len[i-1];
		len[i] = len[i-1] * 2LL;
	}
	FOR(i, 0, 61) ult[i] = pie[i];
	
	int zap;
	cin >> zap;
	while (zap--) {
		int type;
		cin >> type;
		if (type == 3) {
			ll x;
			cin >> x;
			ll pos = get_pos(x);
			int lvl = get_lvl(x);
			//debug(pos, lvl);
			while (lvl != 0) {
				//debug(lvl, pos);
				ll val = get_on_pos(pos, lvl);
				cout << val << ' ';
				lvl--;
				pos = (pos + 1) / 2;
			}
			
			cout << "1\n";
		}
		if (type == 1) {
			ll x, k;
			cin >> x >> k;
			shift(get_lvl(x), k);
		}
		if (type == 2) {
			ll x, k;
			cin >> x >> k;
			int lvl = get_lvl(x);
			k = (k + MOD) % len[lvl];
			for (int i = lvl; i <= 60; ++i) {
				shift(i, k);
				k = (2LL * k) % MOD;
			}
		}
		
	}
	
	
}