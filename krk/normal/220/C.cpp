#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Inf = 1000000000;

int n;
int b[Maxn];
int posa[Maxn], posb[Maxn];
multiset <int> S;
int nil;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		posa[a] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		posb[b[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		S.insert(posb[i] - posa[i]);
	for (nil = 0; nil < n; nil++) {
		set <int>::iterator it = S.lower_bound(nil);
		int res = Inf;
		if (it != S.end()) res = min(res, abs(*it - nil));
		if (it != S.begin()) { it--; res = min(res, abs(*it - nil)); }
		it = S.lower_bound(posb[b[nil]] - posa[b[nil]]); S.erase(it);
		S.insert(n - 1 - posa[b[nil]] + nil + 1);
		printf("%d\n", res);
	}
	return 0;
}