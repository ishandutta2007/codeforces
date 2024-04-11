#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 200005;
const int Maxm = 1048576;

int n;
int p[Maxn], l[Maxn];
int st[Maxm];
int R[Maxn];
int q;
iii seq[Maxn];
int sum[Maxm];
int S[Maxn], slen;
int res[Maxn];

void insertSum(int v, int l, int r, int x, int val)
{
	if (l == r) sum[v] += val;
	else {
		int m = l + r >> 1;
		if (x <= m) insertSum(2 * v, l, m, x, val);
		else insertSum(2 * v + 1, m + 1, r, x, val);
		sum[v] = sum[2 * v] + sum[2 * v + 1];
	}
}

int getSum(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return sum[v];
	else {
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res += getSum(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) res += getSum(2 * v + 1, m + 1, r, max(m + 1, a), b);
		return res;
	}
}

int tellDif(int a, int b)
{
	if (R[a] >= p[b]) return 0;
	return p[b] - R[a];
}

void Add(int ind)
{
	while (slen > 0 && R[ind] >= R[S[slen - 1]]) {
		if (slen - 1 > 0) insertSum(1, 0, n - 1, S[slen - 2], -tellDif(S[slen - 1], S[slen - 2]));
		slen--;
	}
	if (slen > 0) insertSum(1, 0, n - 1, S[slen - 1], tellDif(ind, S[slen - 1]));
	S[slen++] = ind;
}

void Insert(int v, int l, int r, int x, int val)
{
	if (l == r) st[v] = val;
	else {
		int m = l + r >> 1;
		if (x <= m) Insert(2 * v, l, m, x, val);
		else Insert(2 * v + 1, m + 1, r, x, val);
		st[v] = max(st[2 * v], st[2 * v + 1]);
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res = max(res, Get(2 * v, l, m, a, min(m, b)));
		if (m + 1 <= b) res = max(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
		return res;
	}
}

int Get(int l, int r)
{
	int lef = lower_bound(p, p + n, l) - p;
	int rig = upper_bound(p, p + n, r) - p - 1;
	if (lef > rig) return r;
	return max(r, Get(1, 0, n - 1, lef, rig));
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i], &l[i]);
	for (int i = n - 1; i >= 0; i--) {
		R[i] = Get(p[i] + 1, p[i] + l[i]);
		Insert(1, 0, n - 1, i, R[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		seq[i] = iii(ii(a, b), i);
	}
	sort(seq, seq + q);
	int lst = n;
	for (int i = q - 1; i >= 0; i--) {
		while (lst > seq[i].first.first) {
			lst--; Add(lst);
		}
		res[seq[i].second] = getSum(1, 0, n - 1, seq[i].first.first + 1, seq[i].first.second);
	}
	for (int i = 0; i < q; i++)
		printf("%d\n", res[i]);
	return 0;
}