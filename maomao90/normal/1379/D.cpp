#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> plli;

#define INF 100000000

int n, h, m, k;
plli train[200005];
int ans = INF, t;
int ansl, ansr;

ll hourToMins(int hours, int mins) {
	return (ll) hours * m + mins;
}

int main() {
	scanf("%d%d%d%d", &n, &h, &m, &k);
	// add more from n onwards as there might be a cycle
	for (int i = 0; i < n; i++) {
		int hours, mins; scanf("%d%d", &hours, &mins);
		train[i] = plli(hourToMins(hours, mins) % (m / 2), i + 1);
		train[i + n] = plli(hourToMins(hours, mins) % (m / 2) + m / 2, i + 1);
	}
	sort(train, train + 2 * n);
	int l = 0, r = 0;
	while (l <= r && r < 2 * n) {
		while (r < 2 * n && train[r].first - train[l].first < k) r++;
		if (r >= 2 * n) break;
		while (l <= r && train[r].first - train[l].first >= k) {
			if (r - l - 1 < ans) {
				t = train[l].first;
				ans = r - l - 1;
				ansr = r;
				ansl = l;
			}
			l++;
		}
	}
	if (r - l - 1 < ans) {
		t = train[l].first;
		ans = r - l - 1;
		ansr = r;
		ansl = l;
	}
	t += k;
	t %= m / 2;
	printf("%d %d\n", ans, t);
	for (int i = ansl + 1; i < ansr; i++) printf("%d ", train[i].second);
	printf("\n");
	return 0;
}