#include <bits/stdc++.h>
using namespace std;

#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;

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
mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
const LL INF = 1e18;
ll n, m, vmax;
ll seed;

const int maxn = 200100;
ll a[maxn];

int rnd() {
    int ret = seed;
    seed = (seed * 7LL + 13) % 1000000007LL;
    return ret;
}

map <int, ll> q;

inline ll potmod(ll a, ll b, ll mod) {
	ll res = 1;
	a %= mod;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	
	return res % mod;
}

int main() {
	cin >> n >> m >> seed >> vmax;
	q[0] = -1;
	for (int i=1; i<=n; ++i) {
		a[i] = (rnd() % vmax) + 1;
		q[i] = a[i];
	}
	q[n+1] = -1; q[n + 2] = -2;
	
	for (int i=1; i<=m; ++i) {
		int op = (rnd() % 4) + 1;
		int l = (rnd() % n) + 1;
		int r = (rnd() % n) + 1;
		ll x, y=0;
		
		if (l > r) swap(l, r);
		if (op == 3) x = (rnd() % (r - l + 1)) + 1;
		else x = (rnd() % vmax) + 1;

		if (op == 4) y = (rnd() % vmax) + 1;
		
		auto szukaj = [&](int k) -> ll{
			auto it = --q.upper_bound(k);
			return it->e2;
		};
		
		ll pocz = szukaj(l);
		ll kon = szukaj(r + 1);
		// two changes now
		q[l] = pocz;
		q[r + 1] = kon; 

		vector <map<int, ll> :: iterator > ranges;
		for (auto it = q.find(l); it->e1 != r+1; ++it) {
			ranges.pb(it);
		}
		
		ll wynik = 0;
		vector <PLL> values;
		
		trav(it, ranges) {
			if (op == 1) it->e2 += x;
			if (op == 2) it->e2 = x;
			map<int, ll> :: iterator second = it; ++second;
			
			if (op == 4) {
				wynik = (wynik + potmod(it -> e2, x, y) * (second->e1 - it->e1)) % y;
			}
			if (op == 3) {
				values.pb({it->e2, (second->e1 - it->e1)});
			}
		}
		if (op == 3) {
			sort(all(values));
			int s = sz(values);
			for (int j=0; j<s; ++j) {
				if (x <= values[j].e2) {
					cout << values[j].e1 << "\n";
					break;
				}
				else x -= values[j].e2;
			}
		}
		if (op == 4) cout << wynik % y << "\n";
		
		// now unite the segments for speed
		int ile = sz(ranges);
		for (int j = ile - 1; j >= 0; --j) {
			auto it = ranges[j];
			auto sec = it;
			--sec;
			if (sec -> e2 == it -> e2) q.erase(it);
		}
	}
}