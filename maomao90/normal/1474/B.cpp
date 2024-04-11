#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) y = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s - 1; i >= e; i--)
typedef long long ll;
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
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 100000000000000005
#define MOD 1000000007
#define MAXN 100005
#define MAX 30005

int t;
int d;
bool comp[MAX];
vi primes;

int main() {
	for (int i = 2; i * i <= MAX; i++) {
		if (comp[i]) continue;
		for (int j = i * i; j <= MAX; j += i) {
			comp[j] = 1;
		}
	}
	REP (i, 2, MAX) {
		if (!comp[i]) primes.pb(i);
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &d);
		ll fi = *lower_bound(ALL(primes), d + 1);
		ll se = *lower_bound(ALL(primes), fi + d);
		printf("%lld\n", fi * se);
	}
	return 0;
}