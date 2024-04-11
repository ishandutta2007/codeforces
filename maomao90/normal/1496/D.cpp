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

int n;
int p[MAXN], lft[MAXN], rht[MAXN];
vi peak, pts;

int main() {
	scanf("%d", &n);
	REP (i, 1, n + 1) scanf("%d", &p[i]);
	REP (i, 1, n + 1) {
		if (p[i] > p[i - 1] && p[i] > p[i + 1]) peak.pb(i);
	}
	int mx = -1;
	REP (i, 0, peak.size()) {
		int cur = peak[i];
		lft[i] = rht[i] = 1;
		RREP (j, cur - 1, 1) {
			if (p[j] < p[j + 1]) lft[i]++;
			else break;
		}
		REP (j, cur + 1, n + 1) {
			if (p[j] < p[j - 1]) rht[i]++;
			else break;
		}
		int curmx = max(lft[i], rht[i]);
		if (curmx > mx) {
			mx = curmx;
			pts.clear();
			pts.pb(i);
		} else if (curmx == mx) {
			pts.pb(i);
		}
	}
	if (pts.size() > 1) {
		printf("0\n");
		return 0;
	}
	int cur = pts[0];
	if (lft[cur] < rht[cur]) swap(lft[cur], rht[cur]);
	int d = lft[cur];
	if (d % 2 == 1) d--;
	if (rht[cur] > d) printf("1\n");
	else printf("0\n");
	return 0;
}

/*
8
4 5 6 1 3 8 7 2

9
4 5 6 2 1 3 9 8 7
*/