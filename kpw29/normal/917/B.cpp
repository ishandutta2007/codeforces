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

const int maxn = 105;
int n, m;
int arr[maxn][maxn];
bool odw[maxn];
vector <int> top;

void dfs(int x) {
	odw[x] = 1;
	for (int i=1; i<=n; ++i)
		if (!odw[i] && arr[x][i]) {
			dfs(i);
		}
	
	top.push_back(x);
}

bool win[101][101][30];

void solveone() {
	cin >> n >> m;
	FOR(i, 1, n)
		FOR(j, 1, n) arr[i][j] = 0;
		
	FOR(i, 1, m ){
		int a, b; char zn;
		cin >> a >> b >> zn;
		arr[a][b] = zn - 'a' + 1;
	}
	
	FOR(i, 1, n)
		if (!odw[i]) dfs(i);

	for (int kraw=26; kraw>=0; --kraw)
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j) {
			int a = top[i], b = top[j];
			for (int nast = 1; nast <= n; ++nast)
				if (arr[a][nast] != 0 && arr[a][nast] >= kraw) {
					//debug(kraw, a, b, nast, arr[a][nast]);
					for (int potem = arr[a][nast]; potem <= arr[a][nast]; ++potem) {
						if (!win[b][nast][potem]) {
							//mozemy przejsc ta krawedzia
							win[a][b][kraw] = 1;
						}
					}
				}
			
			a = top[j], b = top[i];
			for (int nast = 1; nast <= n; ++nast)
				if (arr[a][nast] != 0 && arr[a][nast] >= kraw) {
					//debug(kraw, a, b, nast, arr[a][nast]);
					for (int potem = arr[a][nast]; potem <= arr[a][nast]; ++potem) {
						if (!win[b][nast][potem]) {
							//mozemy przejsc ta krawedzia
							win[a][b][kraw] = 1;
						}
					}
				}
		}
	
	//FOR(kraw, 0, 2) debug(win[3][3][kraw]);
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (win[i][j][0]) cout << "A";
			else cout << "B";
		}
		cout << "\n";
	}
		
}
	

int main() {
	boost;
	int tests = 1;
	FOR(_, 1, tests) solveone();
}