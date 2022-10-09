
//bad_solution
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
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 100100
const int N = 1e5;
inline ll potmod(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a)%mod;
		b /= 2;
		a = (a * a)%mod;
	}
	return res;
}

ll silnia[maxn], INV[maxn];
int prime[maxn], cnt[maxn]; int liczba[maxn];
vector <int> dziel[maxn];

inline ll binom(int n, int k) {
	if (n < k) return 0;
	if (n == k) return 1;
	return silnia[n] * INV[k] % mod * INV[n - k]%mod;
}

int main() {
	silnia[0] = 1;
	FOR(i, 1, N) {
		silnia[i] = silnia[i-1] * i % mod;
		INV[i] = potmod(silnia[i], mod - 2);
	}
	INV[0] = INV[1];
	
	FOR(i, 2, N) prime[i] = 1, liczba[i] = i;
	FOR(i, 2, N)
	if (prime[i]) {
		for (int j=i+i; j<=N; j+=i) prime[j] = 1;
		for (int j=i; j<=N; j+=i) {
int fd=0;
			while (liczba[j] % i == 0) cnt[j]^=1, liczba[j] /= i,++fd;
if(fd>1) cnt[j] = 1000000;
		}
	}
	
	FOR(i, 1, N)
	  for(int j=i; j<=N; j+=i) dziel[j].pb(i);
	
	int q, n, k;
	boost;
	cin >> q;
	FOR(z, 1, q) {
		cin >> n >> k;
		if (k == 1 && n == 1) {cout << 1 << "\n"; continue; }
		else if (k == 1) {cout << 0<< "\n"; continue; }
		ll result = 0;
		for (auto u : dziel[n]) {
			int dw = n / u;
			if (cnt[u] > 100) continue;

if(cnt[u]) result -= binom(dw-1, k-1);
			else result += binom(dw-1, k-1);
			while (result >= mod) result -= mod;
			while (result < 0) result += mod;
		}
		cout << result << "\n";
	}
}