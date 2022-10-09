#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const ll MAKS = 1e14 + 5;
int n, m, a, b, c, d;
#define maxn 100100
vector <ll> pots;
int t[maxn];
ll k;
map <ll, int> M;

int main()
{
	boost;
	cin >> n >> k;
	pots.pb(1);
	ll POW = k;
	if (k == 1);
	else if (k == -1) pots.pb(-1);
	else
	{
		while (POW <= MAKS)
		{
			pots.pb(POW);
			POW = POW * k;
		}
	}
	FOR(i, 1, n) cin >> t[i];
	ll sum = 0;
	M[sum] = 1;
	ll result = 0;
	FOR(i, 1, n)
	{
		sum += t[i];
		for (auto u : pots) result += M[sum - u];
		M[sum]++;
	}
	cout << result;
}