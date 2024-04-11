#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 998244353
#define MAXN 1000005

int isp[MAXN];
vi primes;
int n;
ll sze[MAXN], dp[MAXN], sum[MAXN];

int main() {
	scanf("%d", &n);
	REP (i, 2, n + 5) isp[i] = 1;
	for (int i = 2; i * i * i * i <= n; i++) {
		if (!isp[i]) continue;
		for (int j = i * i; j * j <= n; j += i) {
			isp[j] = 0;
		}
	}
	for (int i = 2; i * i <= n; i++) {
		if (isp[i]) primes.pb(i);
	}
	REP (i, 1, n + 1) {
		int tmp = i;
		sze[i] = 1;
		for (int j : primes) {
			if (j * j > tmp) break;
			int cur = 0;
			while (tmp % j == 0) {
				tmp /= j;
				cur++;
			}
			sze[i] = sze[i] * (cur + 1) % MOD;
		}
		if (tmp != 1) sze[i] = sze[i] * 2 % MOD;
	}
	dp[1] = 1;
	sum[1] = 1;
	REP (i, 2, n + 1) {
		dp[i] = sum[i - 1] + sze[i];
		dp[i] %= MOD;
		sum[i] = (sum[i - 1] + dp[i]) % MOD;
	}
	printf("%lld\n", dp[n]);
	return 0;
}