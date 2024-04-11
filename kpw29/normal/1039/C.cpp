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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;

ll potmod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a)%mod;
		b >>= 1;
		a = (a * a)% mod;
	}
	return res;
}
const int maxn = 500050;
ll arr[maxn];
int n, m ,k;

map <ll, vector <PII> > M;
ll byl[maxn];
vector <int> graf[maxn];
bool odw[maxn];

void dfs(int x) {
	odw[x] = 1;
	for (auto u : graf[x])
		if (!odw[u]) dfs(u);
}

int main()
{
	boost;
	cin >> n >> m >> k;
	FOR(i, 1, n) byl[i] = -1;
	
	ll result = potmod(2, k);
	result = result * potmod(2, n) % mod;
	FOR(i, 1, n) cin >> arr[i];
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		M[arr[a] ^ arr[b]].push_back(make_pair(a, b));
	}
	
	for (auto u : M) {
		int ILE = 0;
		result += mod - potmod(2, n); //dla tego x na razie odejmujemy
		result %= mod;
		vector <PII> v = u.e2;
		for (auto wie : v) {
			int uu = wie.e1;
			if (byl[uu] != u.e1) ++ILE;
			byl[uu] = u.e1;
			odw[uu] = false;
			graf[uu].clear();
			
			uu = wie.e2;
			if (byl[uu] != u.e1) ++ILE;
			byl[uu] = u.e1;
			odw[uu] = false;
			graf[uu].clear();
		}
		
		for (auto wie : v) {
			graf[wie.e1].pb(wie.e2);
			graf[wie.e2].pb(wie.e1);
		}
		
		int COMP = 0;
		for (auto wie : v) {
			if (!odw[wie.e1]) ++COMP, dfs(wie.e1);
			if (!odw[wie.e2]) ++COMP, dfs(wie.e2);
		}
		
		result = (result + potmod(2, n - ILE) % mod * potmod(2, COMP) % mod)%mod;
	}
	
	cout << result;
}