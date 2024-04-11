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
int n, m, a, b, c, jest, ocz, zap;
ll pref[maxn], suf[maxn], tab[maxn];
ll suma = 0, s = 0;
ll wyn = 0;
int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> tab[i], s += tab[i];
	if (s % 3 != 0) OUT(0);
	s /= 3;

	suma = 0;
	for (int i=n; i>0; --i)
	{
		suf[i] += suf[i+1];
		suma += tab[i];
		if (suma == s) ++suf[i];
	}
	suma = 0;
	for (int i=1; i<=n; ++i)
	{
		suma += tab[i];
		if (suma == s) wyn += suf[i + 2];
	}
	cout << wyn;
}