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
int n, m, a, b, c, jest, ocz, zap, it;
ll pref[maxn];
ll suma = 0, s = 0;
ll wyn = INF;

inline ll sum(int a, int b) {
	return pref[b] - pref[a-1];
}
int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; ++i)
	{
		cin >> a;
		pref[i] = pref[i-1] + a;
	}
	for (int i=1; i<=n-m+1; ++i) 
	{
		ll w = sum(i, i + m - 1);
		if (w < wyn)
		{
			it = i;
			wyn = w;
		}
		
	}
	cout << it;
}