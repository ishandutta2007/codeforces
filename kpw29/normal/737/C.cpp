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
typedef long long int ll;
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
#define maxn 1000100
int n, m, k, a, b, c;
int par[maxn];
int cnt[maxn], pref[maxn];

inline int sum(int a, int b) {
	return pref[b] - pref[a-1];
}

int main() {
	int overall = 0, zlej = 0;
	boost;
	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> par[i];
		if (par[i] == 0) {
			if (i != k) overall++;
		}
		else {
			if (i == k) zlej++;
			else cnt[par[i]]++;
		}
	}
	if (n == 1) {
		if (par[1] == 0) OUT(0);
		OUT(1);
	}
	pref[0] = 0;
	FOR(i, 1, n) pref[i] = pref[i-1] + cnt[i];
	
	int wyn = inf; //length of longest path
	int dziur = 0;
	FOR(i, 1, n-1) {
		if (cnt[i] == 0) ++dziur;
		wyn = min(wyn, max(dziur, overall+ sum(i + 1, n)));
	}
	
	cout << wyn + zlej;
}