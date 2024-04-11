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
typedef int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
#define maxn 4001
const int C = 80;
int M[maxn][2*C+1][C+1][2];
bool bylo[maxn][2*C+1][C+1][2];

int t[maxn], n;
int prw[100010];
ll pref[maxn];

inline ll sum(int A, int B) {
	return pref[B] - pref[A-1];
}

inline ll game(int A, int B, int lm, int ktoTeraz) {
	if (A + B + lm > n) return 0;
	if (bylo[A][A-B+C][lm][ktoTeraz]) return M[A][A-B+C][lm][ktoTeraz];
	bylo[A][A-B+C][lm][ktoTeraz] = 1;
	if (ktoTeraz == 0) {
		ll firstMove = sum(A + 1, A + lm);
		ll w = game(A + lm, B, lm, 1 - ktoTeraz);
		
		ll wall = firstMove - w;
		if (A + B + lm + 1 <= n) {
			ll secMove = sum(A + 1, A + lm + 1);
			ll w2 = game(A + lm + 1, B, lm + 1, 1 - ktoTeraz);
			wall = max(wall, secMove - w2);
		}
		
		M[A][A-B+C][lm][ktoTeraz] = wall;
		return wall;
	}
	else {
		ll firstMove = sum(n - B - lm + 1, n - B);
		ll w = game(A, B + lm, lm, 1 - ktoTeraz);
		
		ll wall = firstMove - w;
		if (A + B + lm + 1 <= n) {
			ll secMove = sum(n - B - lm, n - B);
			ll w2 = game(A, B + lm + 1, lm + 1, 1 - ktoTeraz);
			wall = max(wall, secMove - w2);
		}
		//cout << A << ' ' << B << ' ' << lm << ' ' << wall<<endl;
		M[A][A-B+C][lm][ktoTeraz] = wall;
		return wall;
	}
}
int main() {
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> t[i];
		pref[i] = pref[i-1] + t[i];
	}
	//for (auto u : M) cout << u.e2 << endl;
	cout << game(0, 0, 1, 0);
}