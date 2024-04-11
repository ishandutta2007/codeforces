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
int cnt[MAXN];
vi ans;

int getMex() {
	REP (i, 0, n + 1) {
		if (cnt[i] == 0) return i;
	}
	assert(false);
}

void replace(int id) {
	int mex = getMex();
	cnt[a[id]]--;
	a[id] = mex;
	cnt[a[id]]++;
	ans.pb(id);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		while (getMex() != n) {
			replace(getMex());
		}
		REP (i, 0, n) {
			if (a[i] == i) continue;
			REP (j, 0, n) {
				if (a[j] == i) {
					replace(j);
				}
			}
			replace(i);
			assert(a[i] == i);
		}
		printf("%d\n", (int) ans.size());
		for (int i : ans) printf("%d ", i + 1);
		printf("\n");
		ans.clear();
		REP (i, 0, n + 5) cnt[i] = 0;
	}
	return 0;
}