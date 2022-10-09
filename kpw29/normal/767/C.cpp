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
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short us;
typedef pair <us, us> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef pair <PII, us> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector <int> vi;
const int mod = 1e9+7;
const int inf = 1e9+10;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int W = 1e9;
#define maxn 1000100
ll sum[maxn];
vector <int> v[maxn];
int n, m, a, b, temp[maxn], start;
ll suma, HSUM;
vector <int> ww;
bool odw[maxn];
void dfs(int x) {
	odw[x] = 1;
	sum[x] = temp[x];
	for (auto u : v[x])
	if (!odw[u])
	{
		dfs(u);
		sum[x] += sum[u];
	}
	if (sum[x] == HSUM && x != 0 && x != start) 
	{
		ww.pb(x);
	}
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> a >> b;
		v[a].pb(i);
		if (a == 0) start = i;
		temp[i] = b;
		suma += b;
	}
	suma += 3LL * inf;
	if (suma % 3 != 0) OUT(-1);
	suma -= 3LL * inf;
	HSUM = (suma / 3);
	dfs(0);
	int FIRST = 0;
	FOR(i, 1, n) odw[i] = 0, sum[i] = 0;
	if (ww.size() == 0) OUT(-1);
	if (ww.size() >= 1)
	{
		FIRST = ww[0];
		odw[ww[0]] = 1;
	}
	ww.clear();
	dfs(0);
	if (ww.size() >= 1) cout << FIRST << ' ' << ww[0];
	else cout << -1;
}