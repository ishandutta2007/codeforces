#include <bits/stdc++.h>
//#include <atcoder/modint>
//using namespace atcoder;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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


const int maxn = 300100;
int dr[300100];
vector <int> gdzie[maxn];
int A[maxn], B[maxn];
vector <int> querying[maxn];
int MAX_EQUAL[maxn];

int arr[maxn];
int LAST[maxn];

void add(int p, int val) {
	for (; p < maxn; p += p & (-p)) dr[p] += val;
}

int get(int p) {
	int res = 0;
	for (; p > 0; p -= p & (-p)) res += dr[p];
	return res;
}

void solveone() {
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> arr[i];
		gdzie[arr[i]].push_back(i);
	}
	
	FOR(i, 1, m) {
		cin >> A[i] >> B[i];
		for (int j=1; j<=30; ++j) {
			int r = random(A[i], B[i]);
			if (LAST[arr[r]] == i) continue;
			LAST[arr[r]] = i;
			
			querying[arr[r]].push_back(i);
		}
	}
	
	FOR(i, 1, n) {
		for (auto pos : gdzie[i]) add(pos, 1);
		for (auto que : querying[i]) {
			MAX_EQUAL[que] = max(MAX_EQUAL[que], get(B[que]) - get(A[que] - 1));
		}
		for (auto pos : gdzie[i]) add(pos, -1);
	}
	
	FOR(i, 1, m) {
		int len = B[i] - A[i] + 1;
		int other = len - MAX_EQUAL[i];
		if (MAX_EQUAL[i] <= other + 1) {
			cout << 1 << "\n";
		}
		else {
			cout << MAX_EQUAL[i] - other << "\n";
		}
	}
	
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) {
		solveone();
	}
}