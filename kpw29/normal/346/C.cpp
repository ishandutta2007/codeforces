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
const int maxn = 1000010;

int positions[maxn];
int jump[maxn],n ;

int main() {
	boost;
	cin >> n;
	vector <int> xs = {-1};
	for (int i=1; i<=n; ++i) {
		int a;
		cin >> a;
		xs.push_back(a);
	}
	sort(xs.begin(), xs.end());
	
	int a, b;
	cin >> a >> b;
	int jmp = a-b;
	for (int j=1; j<(int)xs.size(); ++j){
		if (xs[j] == xs[j-1]) continue;
		int u = xs[j];
		int occ = (b / u) * u;
		while (occ < b) occ += u;
		int lt = -1;
		for (int i = occ; i <= a; i += u) {
			if(i-u>=b) positions[i - b] = u;
			lt = i - b;
		}
		
		if (lt != -1) jmp = min(jmp, lt);
	}

	//for (int i = 0; i <= a-b; ++i) debug(i + b, positions[i]);
	int res = 0, curr = a - b;
	for (int i=a-b; i>0; --i) {
		if (curr == i) {
			++res;
			if (jmp >= curr) curr = curr - 1;
			else curr = jmp;
		}
		
		if (positions[i]!=0) jmp = min(jmp, i - positions[i]);
	}

	OUT(res);
}