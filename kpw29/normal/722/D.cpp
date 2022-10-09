#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <int, int> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef pair <ld, ld> PLD;
typedef pair <PLD, ld> PLDD;
typedef pair <PLL, ll> PLLL;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const long long INF = (ll)1e18+3;
int n, m, a, b, c, DL = 0, CC = 0, T;
#define maxn 100100
int t[maxn];
map <int, bool> M;
vector <int> v;

bool check(int k) {
	M.clear(); v.clear();
	FOR(i, 1, n) {
		int a = t[i];
		while (a > k) a /= 2;
		
		while (M[a]) {
			a /= 2;
			if (a == 0) return 0;
		}
		M[a] = 1;
		v.pb(a);
	}
	return 1;
}

int main() {
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> t[i];
	int x = 1, y = 1e9;
	while (x < y) {
		int sr = ((x + y) / 2);
		if (!check(sr)) x = ++sr;
		else y = sr;
	}
	
	check(x);
	for (auto u : v) cout << u << ' ';
}