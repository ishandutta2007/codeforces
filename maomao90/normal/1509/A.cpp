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
int a[MAXN];
vi even, odd;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		even.clear(); odd.clear();
		REP (i, 0, n) {
			scanf("%d", &a[i]);
			if (a[i] % 2 == 0) even.pb(a[i]);
			else odd.pb(a[i]);
		}
		REP (i, 0, even.size()) {
			printf("%d ", even[i]);
		}
		REP (i, 0, odd.size()) {
			printf("%d ", odd[i]);
		}
		printf("\n");
	}
	return 0;
}