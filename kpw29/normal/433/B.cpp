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
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 100100
ll dp[maxn], pref[maxn], tab[maxn];
ll p2[maxn];
int k, zap,a ,b, type,n;
int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> tab[i], pref[i] = pref[i-1] + tab[i];
	sort(tab + 1, tab + n + 1);
	for (int i=1; i<=n; ++i) p2[i] = p2[i-1] + tab[i];
	cin >> zap;
	while (zap--)
	{
		cin >> type >> a >> b;
		if (type == 1) cout << pref[b] - pref[a-1] << endl;
		else cout << p2[b] - p2[a-1] << endl;
	}
}