#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001000;

int n, m, k;
int tab[maxn];
vector <int> v[maxn];

bool odw[maxn];
int sum, ver;

void dfs(int x) {
	sum += (int)v[x].size();
	ver++;
	odw[x] = 1;
	for (auto u : v[x])
		if (!odw[u]) dfs(u);
}
set <PII> q;

int main()
{
	boost;
	int res = 0;
	cin >> k >> n;
	FOR(i, 1, n) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (q.find({a, b}) != q.end()) ++res;
		else {
			q.insert({a, b});
			v[a].pb(b);
			v[b].pb(a);
		}
	}
	
	FOR(i, 1, k)
		if (!odw[i]) {
			sum = 0;
			ver = 0;
			dfs(i);
			//cout << sum << ' ' << ver << endl;
			if (sum == (2 * (ver - 1)));
			else
			{
				int kraw = (sum / 2);
				res += (kraw - ver + 1);
			}
		}
		
	
	cout << res;
}