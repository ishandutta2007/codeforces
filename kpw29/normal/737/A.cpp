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
int n, m, k, a, b, c, dist, czas;
int A[maxn], B[maxn];
int pos[maxn];

ll Tab[maxn], pref[maxn];

int main() {
	boost;
	cin >> n >> k >> dist >> czas;
	FOR(i, 1, n) cin >> A[i] >> B[i];
	FOR(i, 1, k) cin >> pos[i];
	sort(pos + 1, pos + k + 1);
	pos[0] = 0;
	pos[k + 1] = dist;
	
	ll MIN = -1;
	ll sum = 0;
	FOR(i, 1, k+1) {
		ll l = pos[i] - pos[i-1];
		Tab[i] = l;
		MIN = max(MIN, l);
		sum += l;
	}

	sort(Tab + 1, Tab + k + 2);
	pref[0] = 0;
	FOR(i, 1, k+1) pref[i] = pref[i-1] + Tab[i];
	
	ll wyn = INF;
	FOR(i, 1, n) {
		ll v = B[i];
		if (v < MIN) continue;
		int x = 0, y = k + 1;
		while (x < y) {
			int sr = ((x + y) / 2)+1;
			if (Tab[sr] * 2 > v) y = --sr;
			else x = sr;
		}
		//cout << i << ' ' << x << endl;
		ll reszta = pref[x]; //tutaj moge zawsze jechac fastem
		int dl = k + 1 - (x + 1) + 1;
		reszta += v * dl - (pref[k + 1] - pref[x]);
		//cout << i << ' ' << reszta << endl;
		//mozemy reszta razy jechac z predkoscia 2km na kilometr
		if (reszta + 2 * (dist - reszta) <= czas) wyn = min(wyn, (ll)A[i]);
	}
	
	if (wyn == INF) cout << -1;
	else cout << wyn;
}