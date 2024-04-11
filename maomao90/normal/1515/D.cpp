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
int n[2];
int c[2][MAXN];
int cnt[2][MAXN];
priority_queue<ii> pq;

int main() {
	scanf("%d", &t);
	while (t--) {
		int _; scanf("%d%d%d", &_, &n[0], &n[1]);
		REP (i, 0, 2) {
			REP (j, 0, n[i]) {
				scanf("%d", &c[i][j]);
			}
		}
		if (n[0] < n[1]) {
			swap(n[0], n[1]);
			swap(c[0], c[1]);
		}
		REP (i, 0, n[0] + n[1] + 1) cnt[0][i] = cnt[1][i] = 0;
		REP (i, 0, 2) {
			REP (j, 0, n[i]) {
				cnt[i][c[i][j]]++;
			}
		}
		int ans = (n[0] - n[1]) / 2;
		while (!pq.empty()) pq.pop();
		REP (i, 0, n[0] + n[1] + 1) {
			if (cnt[0][i] != cnt[1][i]) {
				pq.push(MP(cnt[0][i] - cnt[1][i], i));
			}
		}
		REP (i, 0, ans) {
			auto [diff, u] = pq.top(); pq.pop();
			cnt[0][u]--;
			cnt[1][u]++;
			diff -= 2;
			n[0]--;
			n[1]++;
			pq.push(MP(diff, u));
		}
		int rem[] = {0, 0};
		REP (i, 0, n[0] + n[1] + 1) {
			if (cnt[0][i] > cnt[1][i]) {
				int diff = cnt[0][i] - cnt[1][i];
				int take = min(rem[1], diff);
				diff -= take;
				rem[1] -= take;
				ans += diff;
				rem[0] += diff;
			} else {
				int diff = cnt[1][i] - cnt[0][i];
				int take = min(rem[0], diff);
				diff -= take;
				rem[0] -= take;
				ans += diff;
				rem[1] += diff;
			}
		}
		printf("%d\n", ans);

	}
	return 0;
}