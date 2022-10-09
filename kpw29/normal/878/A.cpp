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
const int maxn = 1001000;
char type[maxn];
int val[maxn];

int ksor;
int ustal[11];
int odp[11];

int main() {
	boost;
	
	int n;
	cin >> n;
	FOR(i, 1, n) {
		cin >> type[i] >> val[i];
	}
	
	rep(bit, 0, 10) {
		ksor = 0;
		for (int i=n; i>0; --i) {
			if (type[i] == '|' && (val[i] & (1 << bit))) {
				debug(i, bit, ksor);
				ustal[bit] = 1;
				odp[bit] = ksor;
				break;
			}
			if (type[i] == '&' && (val[i] & (1 << bit)) == 0) {
				ustal[bit] = -1;
				odp[bit] = ksor;
				break;
			}
			if (type[i] == '^' && (val[i] & (1 << bit))) {
				ksor ^= (1 << bit);
			}
		}
		if (ustal[bit] == 0) odp[bit] = ksor;
	}
	
	cout << 3 << endl;
	int OR = 0, AND = (1<<10)-1;
	int XOR = 0;
	rep(bit, 0, 10) {
		if (ustal[bit] == 1) OR += (1 << bit);
	}
	
	cout << "| " << OR << endl;
	rep(bit, 0, 10) {
		if (ustal[bit] == -1) AND -= (1 << bit);
	}
	cout << "& " << AND << endl;
	
	rep(bit, 0, 10) {
		XOR ^= odp[bit];
	}
	cout << "^ " << XOR << endl;
}