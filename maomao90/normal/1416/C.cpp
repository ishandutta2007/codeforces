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
#define MAXN 300005
#define MAXK 30

int n;
int a[MAXN];
vector<vi> temp, parts;
ll ansinv;
int ans;

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
	}
	parts.pb(vi(a, a + n));
	RREP (k, MAXK, 0) {
		ll invon = 0, invoff = 0;
		temp.clear();
		for (vi arr : parts) {
			vi on, off;
			ll curon = 0, curoff = 0;
			for (int i : arr) {
				if (i & (1 << k)) {
					on.pb(i);
					curon += off.size();
				} else {
					off.pb(i);
					curoff += on.size();
				}
			}
// 			printf("on: ");
// 			for (int i : on) {
// 				printf("%d ", i);
// 			}
// 			printf("\n");
// 			printf("off: ");
// 			for (int i : off) {
// 				printf("%d ", i);
// 			}
// 			printf("\n");
// 			printf("%d %d\n", curoff, curon);
			if (on.size() > 1) temp.pb(on);
			if (off.size() > 1) temp.pb(off);
			invoff += curoff;
			invon += curon;
		}
		if (invon < invoff) {
			ans += 1 << k;
			swap(invon, invoff);
		}
		ansinv += invoff;
		swap(temp, parts);
	}
	printf("%lld %d\n", ansinv, ans);
	return 0;
}