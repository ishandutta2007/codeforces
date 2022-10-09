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
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, k, c, w, h;
int t[maxn];
int query(int x, int y, int h)
{
	if (x > y || x == -1) return 0;
	if (x == y) return min(1, t[x] - h);
	int MIN = inf;
	for (int i=x; i<=y; ++i) MIN = min(MIN, t[i]);
	int res = (MIN - h);
	int start = -1;
	for (int i=x; i<=y; ++i)
	if (t[i] == MIN) res += query(start, i - 1, MIN), start = -1;
	else if (start == -1) start = i;
	res += query(start, y, MIN);
	return min(y - x + 1, res);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", &t[i]);
	cout << query(1, n, 0);
	
}