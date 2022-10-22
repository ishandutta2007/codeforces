#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 2005;

int n, a[Maxn];
int m, b[Maxn];
ll Sa, Sb;
ll val;
int bst;
ll asum, bsum;
int res[2][2];

void Solve1()
{
	set <ll> S;
	for (int i = 1; i <= m; i++)
		S.insert(2 * b[i]);
	for (int i = 1; i <= n; i++) {
		ll need = -(Sa - Sb - 2ll * a[i]);
		set <ll>::iterator it = S.lower_bound(need);
		if (it != S.end()) {
			ll cand = abs(Sa - Sb - 2ll * a[i] + *it);
			if (cand < val) { val = cand; bst = 1; asum = 2 * a[i]; bsum = *it; }
		}
		if (it != S.begin()) {
			it--;
			ll cand = abs(Sa - Sb - 2ll * a[i] + *it);
			if (cand < val) { val = cand; bst = 1; asum = 2 * a[i]; bsum = *it; }
		}
	}
}

void Solve2()
{
	set <ll> S;
	for (int i = 1; i <= m; i++)
		for (int j = i + 1; j <= m; j++)
			S.insert(2ll * ll(b[i] + b[j]));
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			ll need = -(Sa - Sb - 2ll * ll(a[i] + a[j]));
			set <ll>::iterator it = S.lower_bound(need);
			if (it != S.end()) {
				ll cand = abs(Sa - Sb - 2ll * ll(a[i] + a[j]) + *it);
				if (cand < val) { val = cand; bst = 2; asum = 2ll * ll(a[i] + a[j]); bsum = *it; }
			}
			if (it != S.begin()) {
				it--;
				ll cand = abs(Sa - Sb - 2ll * ll(a[i] + a[j]) + *it);
				if (cand < val) { val = cand; bst = 2; asum = 2ll * ll(a[i] + a[j]); bsum = *it; }
			}
		}
}

void Get1()
{
	for (int i = 1; i <= n; i++)
		if (2 * a[i] == asum) { res[0][0] = i; break; }
	for (int i = 1; i <= m; i++)
		if (2 * b[i] == bsum) { res[0][1] = i; break; }
}

void Get2()
{
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (2ll * ll(a[i] + a[j]) == asum) { res[0][0] = i; res[1][0] = j; break; }
	for (int i = 1; i <= m; i++)
		for (int j = i + 1; j <= m; j++)
			if (2ll * ll(b[i] + b[j]) == bsum) { res[0][1] = i; res[1][1] = j; break; }
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); Sa += a[i];
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]); Sb += b[i];
	}
	val = abs(Sa - Sb); bst = 0;
	Solve1();
	Solve2();
	printf("%I64d\n", val);
	printf("%d\n", bst);
	if (bst == 1) Get1();
	else if (bst == 2) Get2();
	for (int i = 0; i < bst; i++)
		printf("%d %d\n", res[i][0], res[i][1]);
	return 0;
}