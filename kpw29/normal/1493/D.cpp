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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 4LL * 1000000LL * 1000000LL * 1000000LL;

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
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(0);
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}

const int maxn = 200005;
int n, zap;

int pr[maxn + 1];
struct custom_hash {
    unsigned int operator()(int x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

map <unsigned int, int> divisions[maxn];
int ILE[maxn], NEXTPOW[maxn + 1];

int divcnt[maxn];
ll arr[maxn];
ll g;

void mult(int pos, int x) {
	while (x > 1) {
		int dv = pr[x];
		divisions[dv][pos]++;
		if (divisions[dv][pos] == NEXTPOW[dv]) {
			ILE[dv]++;
			if (ILE[dv] == n) {
				ILE[dv] = 0;
				++NEXTPOW[dv];
				g = g * dv % mod;
				for (auto &u : divisions[dv]) {
					if (u.e2 >= NEXTPOW[dv]) ++ILE[dv];
				}
			}
		}
		
		x /= pr[x];
	}
}

int main() {
	boost;
	cin >> n >> zap;
	FOR(i, 1, maxn) pr[i] = i, NEXTPOW[i] = 1;
	FOR(i, 2, maxn) {
		if (pr[i] == i) {
			for (int j=i+i; j<=maxn; j+=i) {
				pr[j] = min(pr[j], i);
			}
		}
	}
	
	g = 1;
	FOR(i, 1, n) {
		arr[i] = 1;
		int num;
		cin >> num;
		mult(i, num);
	}
	
	FOR(i, 1, zap) {
		int pos, num;
		cin >> pos >> num;
		mult(pos, num);
		cout << g << "\n";
	}
		
}