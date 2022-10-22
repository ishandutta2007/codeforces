#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, a, b;
set <ii> S;
int res[Maxn];

bool Exist(int need, ii &res)
{
	set <ii>::iterator it = S.lower_bound(ii(need, 0));
	if (it != S.end() && it->first == need) { res = *it; return true; }
	return false;
}

bool canSolve()
{
	set <ii>::iterator st = S.begin(), en = S.end(); en--;
	ii v = *st, u = *en;
	if (v.first + u.first == a) {
		res[v.second] = res[u.second] = 0;
		S.erase(v); if (v != u) S.erase(u);
		return true;
	} else if (v.first + u.first == b) {
		res[v.second] = res[u.second] = 1;
		S.erase(v); if (v != u) S.erase(u);
		return true;
	} else if (a - v.first < u.first && b - v.first > u.first) {
		ii cand;
		if (Exist(a - v.first, cand)) {
			res[v.second] = res[cand.second] = 0;
			S.erase(v); if (v != cand) S.erase(cand);
			return true;
		}
		return false;
	} else if (a - v.first > u.first && b - v.first < u.first) {
		ii cand;
		if (Exist(b - v.first, cand)) {
			res[v.second] = res[cand.second] = 1;
			S.erase(v); if (v != cand) S.erase(cand);
			return true;
		}
		return false;
	}
	return false;
}

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		int p; scanf("%d", &p);
		S.insert(ii(p, i));
	}
	while (!S.empty())
		if (!canSolve()) { printf("NO\n"); return 0; }
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}