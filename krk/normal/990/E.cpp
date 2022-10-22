#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 1000005;
const ll Inf = 9000000000000000000ll;

int n, m, k;
bool block[Maxm];
int cnt[Maxm];
int a[Maxm];
ll res = Inf;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a; scanf("%d", &a);
		block[a] = true;
	}
	int mx = 0;
	for (int i = 0; i < Maxm; i++)
		if (block[i]) {
			cnt[i] = 1;
			if (i) cnt[i] += cnt[i - 1];
			mx = max(mx, cnt[i]);
		}
	if (block[0]) { printf("-1\n"); return 0; }
	for (int i = 1; i <= k; i++)
		scanf("%d", &a[i]);
	for (int i = mx + 1; i <= k; i++) {
		int cur = 0;
		ll cand = 0;
		while (cur < n)
			if (block[cur]) cur -= cnt[cur];
			else { cand += a[i]; cur += i; }
		res = min(res, cand);
	}
	if (res >= Inf) printf("-1\n");
	else cout << res << endl;
	return 0;
}