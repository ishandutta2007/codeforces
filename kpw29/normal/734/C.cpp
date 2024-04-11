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

ll n, m, k;
#define maxn 1000100
ll a[maxn], b[maxn];

ll c[maxn], d[maxn], one, mana;
ll pref[maxn];

int main() {
	boost;
	ll goal;
	cin >> goal >> n >> m;
	cin >> one >> mana;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	FOR(i, 1, m) cin >> c[i];
	FOR(i, 1, m) cin >> d[i];
	ll best = INF + INF + INF + INF + INF + INF;
	a[0] = one;
	b[0] = 0;
	
	FOR(i, 0, n) {
		if (b[i] <= mana) {
			one = a[i];
			ll zosta = mana - b[i];
			int x = 0, y = m;
			while (x < y) {
				int sr = ((x + y) / 2)+1;
				if (d[sr] > zosta) y = --sr;
				else x = sr;
			}
			
			ll init = goal - c[x];
			if (init <= 0) OUT(0);
			best = min(best, init * one);
		}
	}
	
	cout << best;
}