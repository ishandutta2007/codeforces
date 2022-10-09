#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
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
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1100;
int n, m, k, a, b, c;
double A[maxn], B[maxn];

bool check(long double mid)
{
	long double mass = mid + m, fuel = mid;
	for (int i = 0; i < n; ++i)
	{
		long double delta = (mass / A[i]);
		fuel -= delta; mass -= delta;
		if (fuel < 0) return 0;
		delta = (mass / (B[(i + 1) % n]));
		fuel -= delta; mass -= delta;
		if (fuel < 0) return 0;
	}
	return 1;
}

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 0, n-1) cin >> A[i];
	FOR(i, 0, n-1) cin >> B[i];
	double xx = 0.0, yy = 2e9;
	bool has = 1;
	for (int step = 0; step < 100; ++step)
	{
		long double mid = (xx + yy) / 2;
		if (check(mid)) 
		{
			yy = mid;
			has = 0;
		}
		else xx = mid;
	}
	if (has) OUT(-1);
	cout << fixed << setprecision(15) << xx << endl;
}