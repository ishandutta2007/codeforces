
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
int n, m, k, a, b, c, x, y, DL = 0, T;
#define maxn 2000100

int pref[maxn];
ll help[maxn];

int main()
{
	boost;
	cin >> n >> x >> y;
	FOR(i, 1, n) {
		cin >> a;
		pref[a]++;
		help[a] += a;
	}
	
	FOR(i, 1, 2000000) pref[i] += pref[i-1], help[i] += help[i-1];
	
	ll better = 0;
	while ((better + 1) * y <= x && better<2000001) ++better;
	//cout << better << endl;
	ll res = (ll)n * x;
	
	int C = 2000000;
	for (int gcd = 2; gcd <= 1000000; ++gcd) {
		ll cost = 0, ile = 0;
		for (int j = 1; j * gcd <=C ;++j) {
			int cur = j * gcd;
			ll tmp = pref[cur] - pref[max((int)cur - (int)better - 1, (j - 1) * gcd)];
			ll what = help[cur] - help[max((int)cur - (int)better - 1, (j - 1) * gcd)];
			what = (ll)cur * tmp - what;
			ile += tmp;
			cost += (ll)what * y;
		}
		
		cost += (ll)(n - ile) * x;
		res = min(res, cost);
		
		//cout << gcd << ' ' << cost << ' ' << ile << endl;
	}
	
	cout << res;
	
}