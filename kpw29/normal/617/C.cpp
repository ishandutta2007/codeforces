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
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef pair <PII, ll> PIIL;
typedef pair <int, ll> PIL;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 2010
inline ll sqr(ll a) {
	return a*a;
}
int n;
PII t[maxn];
ll d[maxn][2];
ll odl(int a, int b)
{
	return sqr(t[a].e1 - t[b].e1) + sqr(t[a].e2 - t[b].e2);
}

int main()
{
	scanf("%d%d%d", &n, &t[0].e1, &t[0].e2);
	scanf("%d%d", &t[n+1].e1, &t[n+1].e2);
	for (int i=1; i<=n; ++i) scanf("%d%d", &t[i].e1, &t[i].e2);
	for (int i=1; i<=n; ++i)
	  d[i][0] = odl(0, i), d[i][1] = odl(n+1, i);

	ll res = INF;
	for (int j=0; j<2; ++j) {
	for (int i=1; i<=n; ++i)
	{
		ll wart = d[i][0]; //kwadrat
		ll MIN = 0;
		for (int j=1; j<=n; ++j)
		  if (d[j][0] > wart) MIN = max(MIN, d[j][1]);
		res = min(res, wart + MIN);
	}
	for (int j=1; j<=n; ++j) swap(d[j][0], d[j][1]);
	}

	cout << res;
}