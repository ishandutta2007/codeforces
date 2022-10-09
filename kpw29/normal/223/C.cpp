#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned int ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 4010
ll silnia[maxn], INV[maxn];
ll tab[maxn];
int n, k;

inline ll potmod(ll a, ll b) {
	ll res = 1;
	while (b > 0){
		if (b & 1) res = (res * a) %mod;
		a = (a * a)%mod;
		b /= 2;
	}
	return res;
}
inline ll getBinom(int n, int k) {
	if (k == 0 || n == k || n < k) return 1;
	ll ilo = 1;
	FOR(i, 1, k) ilo = (ilo * (n-i+1))%mod;
	//cout << n << ' ' << k << ' ' << ilo << endl;
	return (ilo * INV[k])%mod;
}

ll dp[maxn], coef[maxn];

int main(){
	silnia[0] = 1;
	FOR(i, 1, maxn-1) silnia[i] = (silnia[i - 1] * i)%mod;
	FOR(i, 1, maxn-1) INV[i] = potmod(silnia[i], mod - 2)%mod;
	cin >> n >> k;
	FOR(i, 1, n) cin >> tab[i];
	
	if (k == 0) {
		FOR(i, 1, n) cout << tab[i] << ' ';
		exit(0);
	}

	for (int i=n; i>0; --i) coef[i] = getBinom(k+i-2, i-1);
	FOR(s, 1, n) {
		FOR(i, s, n) dp[i] += tab[s] * coef[i - s + 1], dp[i] %= mod;
	}
	
	FOR(i, 1, n) cout << dp[i] << ' ';
}