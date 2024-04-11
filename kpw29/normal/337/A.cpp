#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m;
int t[maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; ++i) scanf("%d", &t[i]);
	sort(t+1, t+m+1);
	int wyn = inf;
	for (int i=1; i<=m-n+1; ++i)
	  wyn = min(wyn, t[i + n - 1] - t[i]);
	printf("%d", wyn);
}