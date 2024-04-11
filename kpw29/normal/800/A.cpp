#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(false)
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
#define maxn 1001000
int n, m, k, a, b, c;
int tab[maxn];
long double A[maxn], B[maxn], p;

inline long double zlicz(int pos, long double val)
{
	long double need = A[pos] * val;
	need -= B[pos];
	if (need <= 0) return 0.0;
	return (need / p);
}

inline bool check(long double val)
{
	long double ret = 0.0;
	FOR(i, 1, n) ret += zlicz(i, val);
	return (ret <= val);
}

int main()
{
	boost;
	cin >> n >> p;
	FOR(i, 1, n) cin >> A[i] >> B[i];
	long double x = 0.0, y = 1e18;
	if (check(y)) OUT(-1);
	FOR(step, 1, 100)
	{
		long double sr = (x + y) * 0.5;
		if (check(sr)) x = sr;
		else y = sr;
	}
	cout << x;
}