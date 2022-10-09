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
#define loong 10001000
int n, m, k, a, b, c, w, h;
ll res = 0;
int tab[maxn];
int cnt[10 * maxn];
bool zloz[loong];
ll pref[loong], akt = 0;
ll f(int x)
{
	if (x >= loong) return pref[loong - 1];
	return pref[x];
}
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	{
		scanf("%d", &a);
		cnt[a]++;
	}
	zloz[0] = zloz[1] = 1;
	for (int i=2; i<loong; ++i)
		if (!zloz[i])
		  for (int j = i + i; j < loong; j += i) zloz[j] = 1;
	for (int i=2; i<loong; ++i)
	{
		if (zloz[i]) pref[i] = pref[i-1];
		else 
		{
			akt = 0;
			for (int j = i; j < loong; j += i) akt += cnt[j];
			pref[i] = pref[i-1] + akt;
		}
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d", &a, &b);
		cout << f(b) - f(a - 1) << '\n';
	}
}