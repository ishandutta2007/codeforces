#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, a, b, k,c;
int tab[maxn];
string s;

int main()
{
	boost;
	cin >> n >> k;
	int r = -1;
	FOR(i, 1, n) {
		cin >> tab[i];
		if (i == 1) r = tab[i] % k;
		else 
		{
			int w = tab[i] % k;
			if (w != r) OUT(-1);
		}
	}
	
	FOR(i, 1, n) {
		tab[i] -= r;
		tab[i] /= k;
	}
	int MIN = inf;
	FOR(i, 1, n) MIN = min(MIN, tab[i]);
	ll res = 0;
	FOR(i, 1, n) res += tab[i] - MIN;
	cout << res;
}