#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector <int> vi;
const int mod = 1e9+7;
const int inf = 1e9+10;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100

int ans = 0;
ll W, l, r, LEN;
ll getLen(ll n) {
	if (n <= 1) return 1;
	return 1 + 2 * getLen(n / 2);
}

void solve(ll n, ll pocz, ll kon, ll x, ll y)
{
	//cout << n << ' ' << pocz << ' ' << kon << ' ' << x << ' ' << y << endl;
	if (x <= pocz && y >= kon && pocz == kon)
	{
		ans += (n % 2);
		return;
	}
	ll sr = (pocz + kon - 1) / 2;
	//1..sr, sr + 1, sr + 2, ... kon
	if (x <= sr) solve(n / 2, pocz, sr, x, y);
	if (x <= sr+1 && sr+1 <= y) ans += (n % 2);
	if (y > sr+1) solve(n / 2, sr + 2, kon, x, y);
}

int main()
{
	cin >> W>> l >> r;
	LEN = getLen(W);
	solve(W, 1, LEN, l, r);
	cout << ans;
}