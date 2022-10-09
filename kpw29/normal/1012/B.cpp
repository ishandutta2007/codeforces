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
const int maxn = 500100;

vector <int> v[maxn];
vector <int> x[maxn], y[maxn];
int n, m, k;
int f[maxn];

int find(int a)
{
	if (f[a] == a) return a;
	f[a] = find(f[a]);
	return f[a];
}

int skl;
void lacz(int a, int b)
{
	if (find(a) != find(b)) --skl;
	f[find(a)] = find(b);
}
int A[maxn], B[maxn];

int main()
{
	boost;
	cin >> n >> m >> k;
	if (n == 1) OUT(m - k);
	if (m == 1) OUT(n - k);
	if (k == 0) OUT(n + m - 1);
	FOR(i, 1, n + m) f[i] = i;
	skl = n + m;
	FOR(i, 1, k)
	{
		int a, b;
		cin >> a >> b;
		lacz(a, b + n);
	}
	
	cout << skl - 1;
}