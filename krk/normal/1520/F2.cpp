#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;

int n, T;
int st[Maxm];
vector <ii> seq;

int Ask(int l, int r)
{
	printf("? %d %d\n", l, r); fflush(stdout);
	int res; scanf("%d", &res);
	return r - l + 1 - res;
}

void Create(int v, int l, int r)
{
	st[v] = r - l + 1;
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m);
		Create(2 * v + 1, m + 1, r);
	}
}

int Get(int v, int l, int r, int ind)
{
	st[v]--;
	if (l == r) return l;
	else {
		int m = l + r >> 1;
		if (ind <= st[2 * v]) return Get(2 * v, l, m, ind);
		else return Get(2 * v + 1, m + 1, r, ind - st[2 * v]);
	}
}

int main()
{
	scanf("%d %d", &n, &T);
	int k; scanf("%d", &k);
	for (int i = 1; i <= n; i += 8)
		seq.push_back(ii(Ask(1, min(i + 7, n)), i));
	Create(1, 1, n);
	while (T > 0) {
		int ind = lower_bound(seq.begin(), seq.end(), ii(Get(1, 1, n, k), 0)) - seq.begin();
		assert(0 <= ind && ind < seq.size());
		int lef = seq[ind].second, rig = min(n, seq[ind].second + 7) - 1;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (k <= Ask(1, mid)) rig = mid - 1;
			else lef = mid + 1;
		}
		printf("! %d\n", lef); fflush(stdout);
		if (--T > 0) scanf("%d", &k);
	}
    return 0;
}