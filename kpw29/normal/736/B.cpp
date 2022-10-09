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
#define maxn 1000100
const int MAX = 1e6;
int primes[maxn], dp[maxn], fp[maxn];
vector <int> pp;

inline bool isprime(int x) {
    if (x <= 3) return 1;
	int s = sqrt(x) + 1;
	for (auto u : pp) {
		if (x % u == 0) return 0;
		if (u >= s) return 1;
	}
	return 1;
}
int main() {
	primes[0] = primes[1] = 1;
	for (int i=2; i<=MAX; ++i)
	  if (primes[i] == 0) {
		  pp.pb(i);
		  for (int j=i+i; j<=MAX; j += i) primes[j] = 1;
	  }
	/*FOR(i, 2, MAX)
	  if (primes[i] == 0) fp[i] = i;
	  else fp[i] = fp[i-1];

	for (int i=2; i<=MAX; ++i) {
		if (primes[i] == 0) dp[i] = 1;
		else {
			int ww = fp[i - 2];
			dp[i] = dp[ww] + dp[i - ww];
		}
	}
	
	FOR(i, 1, 100) cout << dp[i] << ' ';*/
	int n;
	cin >> n;
	if (isprime(n)) OUT(1);
	if (n % 2 == 0) {
		OUT(2); //by goldbach conjecture
	}
	else {
		if (isprime(n - 2)) OUT(2);
		OUT(3);
	}
}