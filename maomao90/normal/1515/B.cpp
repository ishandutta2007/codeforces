#include <bits/stdc++.h> 
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
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
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int t;
int n;

bool isSqr(int x) {
	int s = sqrt(x);
	return s * s == x;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool pos = 0;
		if ((n % 2 == 0 && isSqr(n / 2)) || (n % 4 == 0 && isSqr(n / 4))) {
			pos = 1;
		}
		if (pos) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}