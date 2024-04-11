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
int n, m, d;
ll cost;
int tab[maxn];
const int in = 2e4;
inline int odl(int a, int b) {
	return abs((b-a)/d);
}
int main()
{
	cin >> n >> m >> d;
	ll WYN = INF;
	int il = n * m;
	int reszta = -1;
	for (int i=1; i<=il; ++i) 
	{
		cin >> tab[i];
		int r = tab[i] % d;
		if (reszta == -1) reszta = r;
		else if (r != reszta) OUT("-1");
	}
	for (int k=reszta; k<=in; k += d)
	{
		ll tmp = 0;
		for (int i=1; i<=il; ++i) tmp += odl(k, tab[i]);
		WYN = min(WYN, tmp);
	}
	cout << WYN;
}