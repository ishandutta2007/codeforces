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
int tab[maxn];
int lewo[maxn], prawo[maxn];
int k, zap,a ,b, type,n;

int main()
{
	int wyn = 0;
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> tab[i];
	lewo[0] = 0;
	for (int i=1; i<=n; ++i)
	{
		if (tab[i] > tab[i-1]) lewo[i] = lewo[i-1]+1;
		else lewo[i] = 1;
	}
	tab[n+1] = inf;
	prawo[n+1] = 0;
	for (int i=n; i>0; --i)
	{
		if (tab[i] < tab[i+1]) prawo[i] = prawo[i+1]+1;
		else prawo[i] = 1;
	}
	for (int i=1; i<=n; ++i)
	{
		int need = tab[i-1] + 1;
		if (need < tab[i + 1]) wyn = max(wyn, lewo[i-1] + prawo[i+1] + 1);
		else wyn = max(wyn, lewo[i-1] + 1), wyn = max(wyn, prawo[i+1] + 1);
	}
	
	cout << min(n, wyn);
}