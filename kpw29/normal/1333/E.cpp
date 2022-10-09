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
int tab[510][510];

int main() {
	boost;
	cin >> n;
	if (n < 3) OUT(-1);
	int step, skip = 0, ITER = 1;
	if (n == 4) {
		int BASE = n*n - 16;
		int r = n - 3;
		tab[r][r] = BASE + 4; tab[r][r+1] = BASE + 3; tab[r][r+2] = BASE + 6; tab[r][r+3] = BASE + 12; 
		tab[r+1][r] = BASE + 7; tab[r+1][r+1] = BASE + 5; tab[r+1][r+2] = BASE + 9; tab[r+1][r+3] = BASE + 15; 
		tab[r+2][r] = BASE +14; tab[r+2][r+1] = BASE + 1; tab[r+2][r+2] = BASE + 11; tab[r+2][r+3] = BASE + 10; 
		tab[r+3][r] = BASE + 13; tab[r+3][r+1] = BASE + 8; tab[r+3][r+2] = BASE + 16; tab[r+3][r+3] = BASE + 2; 
		FOR(i, 1, n) {
		FOR(j, 1, n) cout << tab[i][j] << ' ';
		cout << "\n";
		}
		exit(0);
	}
	
		int BASE = n*n - 9;
		int r = n - 2;
		tab[r][r] = BASE + 1; tab[r][r + 1] = BASE + 4; tab[r][r + 2] = BASE + 5;
		tab[r+1][r] = BASE + 7; tab[r + 1][r + 1] = BASE + 6; tab[r + 1][r + 2] = BASE + 8;
		tab[r+2][r] = BASE + 9; tab[r + 2][r + 1] = BASE + 3; tab[r + 2][r + 2] = BASE + 2;
	
		step = (n - 3) / 2, skip = 0;
	
	
	for (int i = 1; i <= step; ++i) {
		int cx = 2*i-1, cy = 2*i-1;
		tab[cx][cy] = ITER++;
		FOR(it, 1, n-1-skip) {
			cx++;
			tab[cx][cy] = ITER++;
		}
		cy++;
		tab[cx][cy] = ITER++;
		FOR(it, 1, n-1-skip) {
			cx--;
			tab[cx][cy] = ITER++;
		}
		FOR(it, 1, n-2-skip) {
			cy++;
			tab[cx][cy] = ITER++;
		}
		cx++;
		tab[cx][cy] = ITER++;
		FOR(it, 1, n-3-skip) {
			cy--;
			tab[cx][cy] = ITER++;
		}
		
		skip += 2;
	}
	
	if (n % 2 == 0) {
		int r = n - 3, BS = n*n-15;
		tab[r+1][r] = BS++;
		tab[r+2][r] = BS++;
		tab[r+3][r] = BS++;
		tab[r][r] = BS++;
		tab[r][r+3] = BS++;
		tab[r][r+2] = BS++;
		tab[r][r+1] = BS++;
	}
	
	FOR(i, 1, n) {
		FOR(j, 1, n) cout << tab[i][j] << ' ';
		cout << "\n";
	}
}