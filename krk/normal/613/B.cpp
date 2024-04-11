#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

int n, A, cf, cm;
ll m;
ii cur[Maxn];
ll need[Maxn];
ll best = -1;
int ba, bb;
int res[Maxn];

int main()
{
	scanf("%d %d %d %d", &n, &A, &cf, &cm);
	scanf("%I64d", &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cur[i].first); cur[i].second = i;
	}
	sort(cur, cur + n);
	for (int i = 1; i < n; i++)
		need[i] = need[i - 1] + ll(i) * (cur[i].first - cur[i - 1].first);
	for (int i = n; i >= 0; i--) {
		if (i < n) {
			m -= A - cur[i].first; 
			if (m < 0) break;
		}
		if (i == 0) {
			ll cand = ll(n) * cf + ll(A) * cm;
			if (cand > best) {
				best = cand;
				ba = 0; bb = A;
			}
			break;
		}
		int l = 0, r = i - 1;
		int res = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			if (need[mid] <= m) { res = mid; l = mid + 1; }
			else r = mid - 1;
		}
		ll lim = min(ll(A), ll(m - need[res]) / (res + 1) + cur[res].first);
		ll cand = ll(n - i) * cf + ll(lim) * cm;
		if (cand > best) {
			best = cand;
			ba = i; bb = lim;
		}
	}
	printf("%I64d\n", best);
	for (int i = 0; i < n; i++)
		if (cur[i].first < bb) res[cur[i].second] = bb;
		else res[cur[i].second] = cur[i].first;
	for (int i = ba; i < n; i++)
		res[cur[i].second] = A;
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}