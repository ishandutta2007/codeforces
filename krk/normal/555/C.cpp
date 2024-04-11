#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;

int n, q;
int a[Maxn], b[Maxn];
char c[Maxn];
vector <int> C, R;
int lst[Maxm], ust[Maxm];

int getMax(int st[], int v, int l, int r, int x)
{
	int res = st[v];
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res = max(res, getMax(st, 2 * v, l, m, x));
		else res = max(res, getMax(st, 2 * v + 1, m + 1, r, x));
	}
	return res;
}

void Update(int st[], int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) st[v] = max(st[v], val);
	else {
		int m = l + r >> 1;
		if (a <= m) Update(st, 2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

int main()
{
	scanf("%d %d", &n, &q);
	C.push_back(0); R.push_back(0);
	for (int i = 0; i < q; i++) {
		scanf("%d %d %c", &a[i], &b[i], &c[i]);
		C.push_back(a[i]); R.push_back(b[i]);
	}
	sort(C.begin(), C.end()); C.erase(unique(C.begin(), C.end()), C.end());
	sort(R.begin(), R.end()); R.erase(unique(R.begin(), R.end()), R.end());

	for (int i = 0; i < q; i++) {
		int cind = lower_bound(C.begin(), C.end(), a[i]) - C.begin();
		int rind = lower_bound(R.begin(), R.end(), b[i]) - R.begin();
		if (c[i] == 'U') {
			int row = getMax(ust, 1, 0, C.size() - 1, cind);
			printf("%d\n", R[rind] - R[row]);
			Update(ust, 1, 0, C.size() - 1, cind, cind, rind);
			if (row < rind) Update(lst, 1, 0, R.size() - 1, row + 1, rind, cind);
		} else {
			int col = getMax(lst, 1, 0, R.size() - 1, rind);
			printf("%d\n", C[cind] - C[col]);
			Update(lst, 1, 0, R.size() - 1, rind, rind, cind);
			if (col < cind) Update(ust, 1, 0, C.size() - 1, col + 1, cind, rind);
		}
	}
	return 0;
}