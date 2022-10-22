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
int r[3] = {1, 1, 2}, c[3] = {1, 1, 1};

void nxt(int i) {
	r[i]--;
	c[i]++;
// 	printf(" %d %d\n", r[i], c[i]);
	if (r[i] <= 0) {
		r[i] = c[i] + 1;
		c[i] = 1;
	}
// 	printf(" %d %d\n", r[i], c[i]);
	if (r[i] > n) {
		int ex = r[i] - n;
		r[i] -= ex;
		c[i] += ex;
	}
// 	printf(" %d %d\n", r[i], c[i]);
	if (c[i] > n) {
		c[i] = r[i] + 3;
		r[i] = n;
	}
	if (c[i] > n) {
		r[i] = c[i] = -1;
		return;
	}
}


int main() {
	scanf("%d", &n);
	int no = -1;
	bool done = 0;
	REP (_, 0, n * n) {
		int a; scanf("%d", &a);
		if (done) {
			int other = -1;
			REP (j, 1, 4) {
				if (j != a && j != no) {
					other = j;
					break;
				}
			}
			int id = no == 1 ? 2 : 1;
			printf("%d %d %d\n", other, r[id], c[id]);
			fflush(stdout);
			nxt(id);
			continue;
		}
		REP (i, 1, 3) {
			if (a != i) {
				printf("%d %d %d\n", i, r[i], c[i]);
				fflush(stdout);
				nxt(i);
				if (c[i] == -1) {
					done = 1;
					no = i;
				}
				break;
			}
		}
	}
	return 0;
}