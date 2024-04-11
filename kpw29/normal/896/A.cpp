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
const LL INF = 4e18;
const int maxn = 1000100;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";

string first = "What are you doing while sending \"";
string second = "\"? Are you busy? Will you send \"";
string third = "\"?";

ll len[100010];
char solve(int n, ll k) {
	if (n == 0) return f0[k-1];
	
	if (k <= sz(first)) return first[k - 1];
	k -= sz(first);
	if (k <= len[n - 1]) return solve(n - 1, k);
	k -= len[n-1];
	if (k <= sz(second)) return second[k - 1];
	k -= sz(second);
	if (k <= len[n - 1]) return solve(n - 1, k);
	k -= len[n - 1];
	assert(k <= sz(third));
	return third[k - 1];
}

int main() {
	boost;
	len[0] = sz(f0);
	for (int i=1; i<=100000; ++i) len[i] = min(INF, 2LL * len[i-1] + sz(first) + sz(second) + sz(third));
	
	int q;
	cin >> q;
	string ret = "";
	while (q--) {
		int n; ll k;
		cin >> n >> k;
		if (len[n] < k) ret += ".";
		else {
			char zn = solve(n, k);
			ret += zn;
		}
	}
	
	cout << ret << endl;
	
}