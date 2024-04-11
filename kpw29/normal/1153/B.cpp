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
const int maxn = 105;
int a[maxn], b[maxn], tab[maxn][maxn];

int arr[maxn][maxn];

int main()
{
	boost;
	int n, m, h;
	cin >> n >> m >> h;
	FOR(i, 1, m) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	FOR(i, 1, n)
		FOR(j, 1, m) cin >> tab[i][j];
	
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			if (tab[i][j] == 0) arr[i][j] = 0;
			else
			{
				arr[i][j] = min(b[i], a[j]);
			}
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
}