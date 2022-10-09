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
typedef pair <PII, int> PPI;
typedef unsigned int ui;
typedef vector <int> vi;
const ll mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, m,k, a, b, c;
#define maxn 1000100

int LEN;
int ost[maxn];

vector <PII> odp;
int ILE[maxn];

int main()
{
	boost;
	cin >> n >> k;
	int f = n - k;
	if (f == 1) {
		cout << 2 << endl;
		FOR(i, 2, n) cout << 1 << ' ' << i << endl;
		exit(0);
	}
	
	FOR(i, 1, k) ost[i] = 1, ILE[i] = 0;
	int reszta = 1;
	
	int ans = 0;
	FOR(i, 2, f)
	{
		odp.pb(mp(ost[reszta], i));
		ILE[reszta]++;
		ost[reszta] = i;
		++reszta;
		if (reszta > k) reszta = 1;
	}
	
	ans = ILE[1] + ILE[2] + 2;
	FOR(i, 1, k) odp.pb(mp(ost[i], f + i));
	cout << ans << endl;
	for (auto u : odp) cout << u.e1 << ' ' << u.e2 << "\n";
}