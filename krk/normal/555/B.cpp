#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 200005;

int n, m;
ll l[Maxn], r[Maxn];
lli a[Maxn];
lli seq[Maxn];
ll val[Maxn];
priority_queue <lli> Q;
int res[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%I64d %I64d", &l[i], &r[i]);
	for (int i = 0; i < m; i++) {
		scanf("%I64d", &a[i].first);
		a[i].second = i + 1;
	}
	sort(a, a + m);
	for (int i = 0; i + 1 < n; i++) {
		seq[i] = lli(l[i + 1] - r[i], i);
		val[i] = r[i + 1] - l[i];
	}
	sort(seq, seq + n - 1);
	int pnt = 0;
	for (int i = 0; i < m; i++) {
		while (pnt < n - 1 && seq[pnt].first <= a[i].first) {
			Q.push(lli(-val[seq[pnt].second], seq[pnt].second));
			pnt++;
		}
		if (!Q.empty()) {
			ll nd = -Q.top().first;
			if (a[i].first <= nd) res[Q.top().second] = a[i].second;
			else { printf("No\n"); return 0; }
			Q.pop();
		}
	}
	if (pnt < n - 1) { printf("No\n"); return 0; }
	printf("Yes\n");
	for (int i = 0; i + 1 < n; i++)
		printf("%d%c", res[i], i + 2 < n? ' ': '\n');
	return 0;
}