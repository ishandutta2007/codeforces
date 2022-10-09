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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 998244353;

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

const int maxn = 101000;

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

int n, m, k, tab[maxn];
string s;

int CNT[maxn], wh[maxn];
int ILE[maxn], t;
set <PII> q;
set <int> sa;

int main() {
	boost;
	cin >> t;
	while (t--) {
		q.clear(); sa.clear();
		cin >> n;
		FOR(i, 1, n) {
			cin >> tab[i];
			wh[tab[i]] = i;
			ILE[i] = 1;
			q.insert(mp(-1, i));
			sa.insert(i);
		}
		
		bool ans = true;
		FOR(i, 1, n) {
			int gdzie = wh[i];
			if (-ILE[gdzie] != (*q.begin()).e1) {
				ans = false;
				break;
			}
			
			int val = -(*q.begin()).e1;
			sa.erase(gdzie);
			q.erase(mp(-ILE[gdzie], gdzie));
			
			if (sa.lower_bound(gdzie) != sa.end()) {
				int nt = *sa.lower_bound(gdzie);
				//debug(i, nt);
				q.erase(mp(-ILE[nt], nt));
				ILE[nt] += val;
				q.insert(mp(-ILE[nt], nt));
			}
		}
		
		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}
}