#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

int n, q;
ll v[Maxn], c[Maxn];
ll a, b;
ii b1, b2;
ll best[Maxn];

ll getRes()
{
	b1 = b2 = ii(0ll, 0ll);
	for (int i = 1; i <= n; i++) best[i] = -Inf;
	ll res = 0ll;
	for (int i = 0; i < n; i++) {
		// take the same
		if (best[c[i]] != -Inf) best[c[i]] = max(best[c[i]], best[c[i]] + a * v[i]);
		// otherwise
		if (b1.second != c[i]) best[c[i]] = max(best[c[i]], b1.first + b * v[i]);
		else best[c[i]] = max(best[c[i]], b2.first + b * v[i]);
		if (b2.second == c[i]) b2 = ii(0ll, 0ll);
		else if (b1.second == c[i]) { b1 = b2; b2 = ii(0ll, 0ll); }
		if (best[c[i]] > b1.first) { b2 = b1; b1 = ii(best[c[i]], c[i]); }
		else if (best[c[i]] > b2.first) b2 = ii(best[c[i]], c[i]);
		res = max(res, best[c[i]]);
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &v[i]);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &c[i]);
	while (q--) {
		scanf("%I64d %I64d", &a, &b);
		printf("%I64d\n", getRes());
	}
	return 0;
}