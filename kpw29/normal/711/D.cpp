#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define x first
#define y second
#define tysiac 1010
#define milion 1000100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define OUT(x) { cout << x; return 0; }
#define PRINT(x, y) {printf("%d %d\n", x, y); return;} 
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
typedef pair <double, int> PDI;

const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int T, n, m, K, a, b, c, k, d, g, Q, DL;

#define maxn 1000100
int t[maxn];
vector <int> v[maxn];
int deg[maxn];
bool odw[maxn];

ll wyn;
void LeafCut() {
	queue <int> q;
	while (!q.empty()) q.pop();
	FOR(i, 1, n)
	  if (!deg[i]) q.push(i);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		odw[x] = 1;
		wyn = (wyn * 2)%mod;
		for (auto u : v[x]) {
			deg[u]--;
			if (!deg[u]) q.push(u);
		}
	}
}
ll pot[maxn];
int main() {
	boost;
	cin >> n;
	pot[0] = 1;
	FOR(i, 1, n) pot[i] = (pot[i-1] * 2) % mod;
	wyn = 1;
	FOR(i ,1, n) {
		cin >> t[i];
		deg[t[i]]++;
		v[i].pb(t[i]);
	}
	LeafCut();
	FOR(i, 1, n)
	  if (!odw[i]) {
		  int j = i, len = 0;
		  while (!odw[j]) {
			  ++len;
			  odw[j] = 1;
			  j = t[j];
		  }
		  ll A = (pot[len] - 2 + mod) % mod;
		  wyn = (wyn * A) % mod;
	  }
	cout << wyn;
}