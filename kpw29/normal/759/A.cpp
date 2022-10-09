#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector<int> vi;
typedef bitset<51> bset;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
int T, n, m, a, b, c;
int tab[maxn];
bool odw[maxn];
vector <int> v[maxn];
void dfs(int x) {
	odw[x] = 1;
	for (auto u : v[x])
	if (!odw[u]) dfs(u);
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> tab[i];
		v[i].pb(tab[i]);
	}
	int ans = 0;
	int skl = 0;
	FOR(i, 1, n)
	if (!odw[i]) {
		skl++;
		dfs(i);
	}
	if (skl > 1) ans += skl;
	
	int sum = 0;
	FOR(i, 1, n) {
		cin >> a;
		sum += a;
	}
	if (sum % 2 == 0) ++ans;
	cout << ans;
}