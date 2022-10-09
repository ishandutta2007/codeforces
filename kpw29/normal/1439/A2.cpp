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

const int maxn = 1000100;
int n, m;


string s[110];
bool tab[110][110];
vector <vector <int> > res;

void oper(int a, int b, int c, int d, int e, int f) {
	tab[a][b] ^= 1;
	tab[c][d] ^= 1;
	tab[e][f] ^= 1;
	res.push_back({a,b,c,d,e,f});
}

vector <vector <int> > solver[2][2][2][2];
int xd[2][2];

void zamien(int cell) {
	PII du = {0, 0};
	if (cell == 1) du = {0, 1};
	if (cell == 2) du = {1, 1};
	if (cell == 3) du = {1, 0};
	
	FOR(i, 0, 1)
		FOR(j, 0, 1)
			if (make_pair(i, j) != du) xd[i][j] ^= 1;
}

vector <int> opuj(int opp) {
	if (opp == 0) return {1, 2, 2, 1, 2, 2};
	if (opp == 1) return {1, 1, 2, 1, 2, 2};
	if (opp == 2) return {1, 1, 1, 2, 2, 1};
	if (opp == 3) return {1, 2, 1, 1, 2, 2};
}

void make_solver() {
	for (int a = 0; a < 4; ++a)
		for (int b=0; b<4; ++b)
			for (int c=0; c<4; ++c){
					FOR(i, 0, 1)
						FOR(j, 0, 1) xd[i][j] = 0;
					
					zamien(a);
					zamien(b);
					zamien(c);
					if (solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].empty()) {
						solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(a));
						solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(b));
						solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(c));
					}
				}
				
	for (int a = 0; a < 4; ++a)
		for (int b=0; b<4; ++b)
			for (int c=0; c<4; ++c)
				for (int d=0; d<4; ++d) {
					FOR(i, 0, 1)
						FOR(j, 0, 1) xd[i][j] = 0;
					
					zamien(a);
					zamien(b);
					zamien(c);
					zamien(d);
					if (solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].empty()) {
						solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(a));
						solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(b));
						solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(c));
						solver[xd[0][0]][xd[0][1]][xd[1][0]][xd[1][1]].push_back(opuj(d));
					}
				}

		
}

void solveone() {
	cin >> n >> m;
	int N = n; int M = m;
	res = {};
	FOR(i, 1, n) cin >> s[i];
	FOR(i, 1, n)
		FOR(j, 1, m)
			if (s[i][j - 1] == '1') tab[i][j] = 1;
			else tab[i][j] = 0;
	
	while (m > 2) {
		for (int i=1; i < n; ++i) {
			if (tab[i][m]) {
				if (tab[i+1][m]) oper(i, m-1, i, m, i+1, m);
				else oper(i, m-1, i, m, i+1, m-1);
			}
		}
		
		if (tab[n][m]) oper(n, m, n, m-1, n-1, m-1);
		m--;
	}
	
	while (n > 2) {
		if (tab[n][1] && tab[n][2]) {
			oper(n, 1, n, 2, n-1, 1);
		}
		else if (tab[n][1]) {
			oper(n, 1, n-1, 2, n-1, 1);
		}
		else if (tab[n][2]) {
			oper(n, 2, n-1, 2, n-1, 1);
		}
		--n;
	}
	
	for (auto move : solver[tab[1][1]][tab[1][2]][tab[2][1]][tab[2][2]]) {
		res.push_back(move);
	}
	
	cout << (int)res.size() << "\n";
	for (auto u : res) {
		for (int j=0; j<6; ++j) cout << u[j] << ' ';
		cout << "\n";
	}
	
}

int main() {
	boost;
	make_solver();
	
	FOR(a, 0, 1)
		FOR(b, 0, 1)
			FOR(c, 0, 1)
				FOR(d, 0, 1) {
					if (solver[a][b][c][d].empty()) debug(a, b, c, d);
					assert(!solver[a][b][c][d].empty());
				}
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}