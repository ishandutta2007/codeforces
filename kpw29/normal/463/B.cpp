#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18+3;
int tests, n, m, a, b, c, d,k;

#define maxn 1000100
ll tab[maxn];
int main()
{
	boost;
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> tab[i];
	ll ener = 0;
	ll wyn = INF;
	for (int i=0; i<n; ++i)
	{
		ener += (tab[i] - tab[i + 1]);
		wyn = min(wyn, ener);
	}
	if (wyn < 0) cout << -wyn;
	else cout << 0;
}