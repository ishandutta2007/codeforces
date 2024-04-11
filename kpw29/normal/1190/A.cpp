#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll mod = 1e9+696969;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
int a, b, c;
const int maxn = 1000100;
ll n, m, k;
ll tab[maxn];
bool odw[maxn];

int main()
{
	boost;
	cin >> n >> m >> k;
	FOR(i, 1, m) cin >> tab[i];
	
	int score = 0;
	FOR(i, 1, m)
	{
		if (odw[i]) continue;
		ll ile = tab[i] - (i - 1);
		ll pos = (ile % k);
		if (pos == 0) pos += k;
		//cout << "i: " << pos << endl;
		
		++score;
		int j = i;
		while (j < m && pos + tab[j + 1] - tab[i] <= k) ++j;
		//cout << i << ' ' << j << endl;
		FOR(xd, i, j) odw[xd] = true;
	}
	
	cout << score;
}