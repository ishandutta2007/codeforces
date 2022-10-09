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
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
const int inf = 1e9+9;
const int mod = 998244353;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
int n, m, a, b, c;
const int maxn = 1000100;
vector <int> arr[maxn];
int sz[maxn];
vector <int> ins[maxn], deel[maxn];

multiset <int> liczby[maxn];

int MAX[maxn];
int KT[maxn], w;

int main()
{
	boost;
	cin >> n >> w;
	ll BASE = 0;
	FOR(i, 1, n){ 
		cin >> sz[i];
		arr[i].resize(sz[i]);
		FOR(j, 0, sz[i] - 1) {
			cin >> arr[i][j];
			MAX[i] = max(MAX[i], arr[i][j]);
		}
		
		BASE += MAX[i];
		FOR(j, 1, sz[i]) ins[j].pb(i);
		FOR(j, w - sz[i] + 1, w) deel[j].pb(i);
	}

	FOR(col, 1, w) {
		ll WYN = BASE;
		for (auto u : ins[col]) {
			liczby[u].insert(- arr[u][col - 1]);
			WYN -= MAX[u];
			if (col + sz[u] <= w)
			{
				WYN -= min(*liczby[u].begin(), 0);
			}
			else WYN -= *liczby[u].begin();
		}
		
		for (auto u : deel[col]) {
			if (col > sz[u]) {
				WYN -= MAX[u];
				WYN -= min(*liczby[u].begin(), 0);
			}

			liczby[u].erase(liczby[u].find(- arr[u][KT[u]]));
			KT[u]++;
		}
		
		cout << WYN << ' ';
	}
	
}