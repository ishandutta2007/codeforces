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
const long long INF = 1e18+3;
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

const int maxn = 1010000;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, k;

int turns[3000001];
bool arr[3010];
string s;
bool tmp[3010];
int TURN;
ll ones = 0;
vector <int> swp;

inline bool sorted() {
	int zeros = n - ones;
	FOR(i, 1, zeros)
		if (arr[i]) return false;
	
	return true;
}

int gather() {
	int res = 0;
	int i = 1;
	while (i < n) {
		if (arr[i] && !arr[i+1]) {
			swap(arr[i], arr[i+1]);
			swp.push_back(i);
			i += 2;
			++res;
		}
		else i++;
	}
	
	return res;
}

int main() {
	boost;
	cin >> n >> k;
	cin >> s;
	ll invs = 0;
	for (int i=0; i<n; ++i) {
		if (s[i] == 'R') arr[i + 1] = 1;
		else arr[i + 1] = 0;
		
		if (arr[i + 1]) ++ones;
		else invs += ones;
	}
	
	FOR(i, 1, n) tmp[i] = arr[i];
	
	if (invs < k) OUT(-1);
	while (!sorted()) {
		TURN++;
		turns[TURN] = gather();
	}
	
	ll sm = 0;
	if (k < TURN) OUT(-1);
	
	int ITER = TURN;
	while (TURN < k) {
		while (turns[ITER] == 1) --ITER;
		turns[++TURN] = 1;
		turns[ITER]--;
	}
	
	FOR(i, 1, TURN) {
		sm += turns[i];
	}
	assert(sm == invs);
	
	FOR(i, 1, n) arr[i] = tmp[i];
	
	//da sie
	int swaps = 0;
	FOR(i, 1, k) {
		int how = turns[i];
		cout << how << ' ';
		for (int j = 0; j < how; ++j) cout << swp[swaps++] << ' ';
		cout << "\n";
	}
}