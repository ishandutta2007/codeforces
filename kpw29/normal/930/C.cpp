#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REYNA(i, a, b) for (int i=(a); i<(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int maxn = 100100;
int tab[maxn];
int LE[maxn], RE[maxn];
int dr[maxn + 100];

inline void add(int p, int v) {
	++p;
	for (; p < maxn; p += p & (-p)) dr[p] = max(dr[p], v);
}
inline int get(int p) {
	++p;
	int res = 0;
	for (; p > 0; p -= p & (-p)) res = max(res, dr[p]);
	return res;
}

int main()
{
	boost;
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n) {
		int a, b;
		cin >> a >> b;
		tab[b + 1]--;
		tab[a]++;
	}
	FOR(i, 1, m) tab[i] += tab[i-1];
	FOR(i, 1, m) {
		LE[i] = 1 + get(tab[i]);
		add(tab[i], LE[i]);
	}
	
	FOR(i, 0, maxn-1) dr[i] = 0;
	for (int i=m; i>0; --i) {
		RE[i] = 1 + get(tab[i]);
		add(tab[i], RE[i]);
	}
	
	int res = 0;
	FOR(i, 1, m) res = max(res, RE[i] + LE[i] - 1);
	cout << res;
}