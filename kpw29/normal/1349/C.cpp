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
const int maxn = 1010;
bool tab[maxn][maxn];
bool nt[maxn][maxn];
int n, m;
PII pole[100100];
ll timee[100100];

const int C = 100;

inline bool nast(int i, int j) {
	int ans = (1 ^ tab[i][j]);
	if (i < n && tab[i + 1][j] == tab[i][j]) return ans;
	if (j < m && tab[i][j+1] == tab[i][j]) return ans;
	if (i > 1 && tab[i-1][j] == tab[i][j]) return ans;
	if (j > 1 && tab[i][j-1] == tab[i][j]) return ans;
	return tab[i][j];
}

void display() {
	cout << "New iteration\n";
	FOR(i, 1, n) {
		FOR(j, 1, m) cout << tab[i][j] << ' ';
		cout << endl;
	}
	
}

void new_iteration() {
	FOR(i, 1, n)
		FOR(j, 1, m) nt[i][j] = nast(i, j);
	
	FOR(i, 1, n)
		FOR(j, 1, m) tab[i][j] = nt[i][j];
}
vector <int> queries[101];
int odp[100100];

void ans(int val) {
	for (auto u : queries[val]) {
		odp[u] = tab[pole[u].e1][pole[u].e2];
	}
}

int conv[1010][1010];
bool odw[1010][1010];

int zap;

int main() {
	boost;
	cin >> n >> m >> zap;
	FOR(i, 1, n) {
		string s;
		cin >> s;
		FOR(j, 1, m) tab[i][j] = (s[j-1] == '1');
		//FOR(j, 1, m) tab[i][j] = rand()%2;
	}
	
	FOR(i, 1, zap) {
		cin >> pole[i].e1 >> pole[i].e2 >> timee[i];
		if (timee[i] <= C) queries[timee[i]].pb(i);
		odp[i] = 2;
	}
	
	queue <PII> q;
	
	FOR(i, 1, n)
		FOR(j, 1, m) {
			int val = nast(i, j);
			if (val != tab[i][j]) {
				odw[i][j] = 1;
				conv[i][j] = 1;
				q.push({i, j});
			}
		}
	
	while (!q.empty()) {
		PII cell = q.front();
		q.pop();
		int i = cell.e1, j = cell.e2;
		if (i > 1 && !odw[i-1][j]) {
			odw[i-1][j] = 1;
			conv[i-1][j] = conv[i][j] + 1;
			q.push({i - 1, j});
		}
		
		if (j > 1 && !odw[i][j-1]) {
			odw[i][j-1] = 1;
			conv[i][j-1] = conv[i][j] + 1;
			q.push({i, j - 1});
		}
		
		if (i < n && !odw[i+1][j]) {
			odw[i+1][j] = 1;
			conv[i+1][j] = conv[i][j] + 1;
			q.push({i + 1, j});
		}
		
		if (j < m && !odw[i][j+1]) {
			odw[i][j+1] = 1;
			conv[i][j+1] = conv[i][j] + 1;
			q.push({i, j + 1});
		}
	}
	
	
	FOR(step, 1, zap) {
		int i = pole[step].e1, j = pole[step].e2;
		if (conv[i][j] == 0 || timee[step] < conv[i][j]) cout << tab[i][j] << "\n";
		else {
			ll dist = timee[step] - conv[i][j];
			if (dist % 2 == 0) cout << (1 ^ tab[i][j]);
			else cout << tab[i][j];
			cout << "\n";
		}
	}
	
}