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
const ll MOD = 1e9+696969;

/*namespace Color {
enum Code {
  FG_RED     = 31,
  FG_GREEN   = 32,
  FG_YELLOW  = 33,
  FG_BLUE    = 34,
  FG_DEFAULT = 39
};
class ColorDebugger {
  Code code;
 public:
  ColorDebugger(Code pCode) : code(pCode) {}
  template <class T>
  ColorDebugger& operator<<(const T &other) {
    cout << "\033[" << code << "m" << other << "\033[" << FG_DEFAULT << "m";
    return *this;
  }
  ColorDebugger& operator<<(ostream&(*pManip)(ostream&)){
    (*pManip)(cout);
    return *this;
  }
};
}

using namespace Color;
ColorDebugger gout(FG_GREEN);
ColorDebugger rout(FG_RED);*/

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
const int maxn = 600100;




ll p[maxn];
ll arr[maxn];

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll get(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

int MAGIC = 300000;

int main() {
	int MAX_D = sqrt(MAGIC) + 1;
	boost; int n;
	cin >> n;
	FOR(i, 1, n) cin >> arr[i];
	
	FT values(maxn);
	FT counts(maxn);
	vector <int> smalls;
	FOR(i, 1, n) {
		p[i] = p[i-1];
		if (arr[i] <= MAX_D) {
			for (int j=1; j<i; ++j) {
				p[i] += arr[i] % arr[j];
				p[i] += arr[j] % arr[i];
			}
			smalls.pb(arr[i]);
		}
		else {
			// first for values >= x
			ll x = arr[i];
			
			// and now resolve values <= x: SMALL (we take everything, and ignore)
			trav(y, smalls) {
				p[i] += x % y;
				p[i] += y % x;
			}
			
			for (int k = 1; ; k++) {
				int MIN = k * x;
				int MAX = (k + 1) * x; //exclusive
				if (MIN > MAGIC) break;
				ll cnt = counts.get(MAX) - counts.get(MIN);
				ll total_sum = values.get(MAX) - values.get(MIN);
				p[i] += total_sum - cnt * MIN;
				p[i] += cnt * x;
			}
			
			// and resolve MAGIC < y <= x, the factor < SQ
			
			for (int d = 1; ; ++d) {
				int MAX = x / d; //inclusive
				int MIN = x / (d + 1) + 1; //inclusive
				if (MAX <= MAX_D) break;
				if (MAX < MIN) continue;
				ll cnt = counts.get(MAX + 1) - counts.get(MIN);
				ll total_sum = values.get(MAX + 1) - values.get(MIN);
				
				// x is bigger
				p[i] += cnt * x - total_sum * d;
				p[i] += total_sum;
			}
			
			// FW updates
			counts.update(x, 1);
			values.update(x, x);
		}
		
	}
	
	
	FOR(i, 1, n) cout << p[i] << ' ';
}