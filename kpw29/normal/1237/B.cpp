#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001000;
string s;
int n, m, a, b, c;
int tab[maxn];

int perm[maxn], where[maxn];
int ID[maxn];

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> tab[i];
		ID[tab[i]] = i;
	}
	FOR(i, 1, n) {
		cin >> a;
		perm[i] = ID[a];
	}
	
	int res = 0, MIN = n + 1;
	for (int i=n; i>0; --i) {
		if (perm[i] > MIN) ++res;
		MIN = min(MIN, perm[i]);
	}
	
	cout << res;
}