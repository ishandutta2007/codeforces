#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 500005;

int n, g, r;
int mod;
int L[Maxn];
ll all;
int m;
int t[Maxn];
ii P[Maxn];
ll res[Maxn];
set <ii> S;
int nil;

int main()
{
	scanf("%d %d %d", &n, &g, &r);
	mod = g + r;
	for (int i = 0; i <= n; i++) {
		scanf("%d", &L[i]);
		all += L[i];
	}
	int q; scanf("%d", &q);
	m = q;
	for (int i = 0; i < q; i++) {
		scanf("%d", &t[i]);
		S.insert(ii(t[i] % mod, i));
	}
	for (int i = 0; i < n; i++) {
		nil = (nil + L[i]) % mod;
		int my = mod - 1 - nil;
		int v = -1;
		auto it = S.lower_bound(ii(my + 1, 0));
		while (!S.empty()) {
			if (it == S.begin()) it = S.end();
			it--;
			int cur = (it->first + nil) % mod;
			if (cur >= g) {
				if (v == -1) v = m++;
				P[it->second] = ii(v, mod - cur);
				S.erase(it++);
			} else break;
		}
		if (v != -1)
			S.insert(ii((mod - nil) % mod, v));
	}
	for (int i = m - 1; i >= 0; i--)
		if (P[i].first) res[i] = res[P[i].first] + P[i].second;
	for (int i = 0; i < q; i++)
		printf("%I64d\n", ll(t[i]) + res[i] + all);
    return 0;
}