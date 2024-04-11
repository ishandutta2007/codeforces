#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int maxn = 1e5;

ll A[maxn];

ll solve(ll s, ll x) {
	ll sqrts = sqrt(s);
	for (ll k = sqrt(x) + 1; k >= 1; k--) {
		if (x % k != 0) continue;
		ll n = x / k - k;
		if (n <= 0 || n & 1) continue; // n >= 1
		n /= 2;

		if (n < sqrts - 5LL || n * n <= s) continue;

		// smallest possible
		return n * n - s;
	}
	return -1;
}

int main() {
int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i += 2) scanf("%lld", &A[i]);

	ll sum = 0;
	for (int i = 0; i < n; i += 2) {
		A[i] = solve(sum, A[i + 1]);
		// cerr << i << ": " << A[i] << endl;
		if (A[i] < 0) {
			return printf("No\n"), 0;
		}
		sum += A[i];
		sum += A[i + 1];
	}

	printf("Yes\n");
	REP(i, n) printf("%lld%c", A[i], " \n"[i==n-1]);

	return 0;
}