#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, k;
int a[N];
vector<pair<int,int>> vals;
long long ans = 0;
int cnt[N];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		vals.push_back(make_pair(a[i], i));
	}
	sort(vals.begin(), vals.end());
	reverse(vals.begin(), vals.end());
	for (int i = 0; i < m * k; ++i) {
		ans += vals[i].first;
		cnt[vals[i].second] = 1;
	}
	printf("%lld\n", ans);
	int now = 0;
	vector<int> pos;
	for (int i = 1; i <= n; ++i) {
		now += cnt[i];
		if (now == m) {
			pos.push_back(i);
			now = 0;
		}
	}
	pos.pop_back();
	for (int v : pos) {
		printf("%d ", v);
	}
}