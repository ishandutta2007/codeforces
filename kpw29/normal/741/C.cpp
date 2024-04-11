#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned int ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 200100

int stan[maxn];
int DP[maxn], n, a,b ,N;
int para[maxn], A[maxn], B[maxn];

inline int nt(int x) {
	if (x == N) return 1;
	return x + 1;
}

int main() {
	srand(2137);
	boost;
	cin >> n;
	if (n == 1) OUT("1 2");
	if (n == 2) OUT("1 2\n1 2");
	N = 2 * n;
	FOR(i, 1, n) {
		cin >> a >> b;
		para[a] = b;
		para[b] = a;
		A[i] = a; B[i] = b;
	}
	FOR(i, 1, N) stan[i] = -1;
	stan[1] = 0; stan[para[1]] = 1;
	
	FOR(i, 1, N) {
		if (stan[i] == -1) {
			stan[i] = 1 - stan[i-1];
			stan[para[i]] = stan[i-1];
		}
	}
	
	FOR(reparas, 0, 1000) {
		FOR(i, 1, N) {
			int nast = nt(i);
			int n2 = nt(nast);
			if (stan[i] == stan[nast] && stan[n2] == stan[i]) {
				int r = rand()%3;
				int all = i;
				if (r == 1) all = nast;
				if (r == 2) all = n2;
				stan[all] ^= 1;
				stan[para[all]] ^= 1;
			}
		}
	}
	
	bool fajnosc = 1;
	FOR(i, 1, N) {
		assert(stan[i] + stan[para[i]] == 1);
		int nast = nt(i);
		int n2 = nt(nast);
		if (stan[i] == stan[nast] && stan[n2] == stan[i]) fajnosc = 0;
	}
	
	if (!fajnosc) cout << "-1";
	else {
		FOR(i, 1, n) cout << 1 + stan[A[i]] << ' ' << 1 + stan[B[i]] << "\n";
	}
}