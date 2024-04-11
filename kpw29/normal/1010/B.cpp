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
const int maxn = 1000100;
int n, m, k, a, b, c, step;
bool correct[35];

int ask(int x)
{
	cout << x << endl;
	int ans;
	cin >> ans;
	if (ans == 0) exit(0);
	return ans;
}

int query(int x)
{
	cout << x << endl;
	int ans;
	cin >> ans;
	if (ans == 0) exit(0);
	if (!correct[step])
	{
		if (ans == 1) ans = -1;
		else ans = 1;
	}
	++step;
	if (step == n + 1) step = 1;
	return ans;
}

int main()
{
	cin >> m >> n;
	for (int i=1; i<=n; ++i)
		if (ask(1) == 1) correct[i] = 1;
		else correct[i] = 0;
	
	int xx = 1, yy = m;
	step = 1;
	while (true)
	{
		int mid = (xx + yy) / 2;
		if (query(mid) == 1) xx = mid + 1;
		else yy = mid - 1;
	}
}