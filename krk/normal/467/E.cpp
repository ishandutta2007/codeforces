#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;
const int Maxm = 2097152;
const int Inf = 1000000000;

int n;
int a[Maxn];
vector <int> un;
ii mn[Maxm];
int fir[Maxn], lst[Maxn], cnt[Maxn];
int tmp[Maxn], tlen;
int res[Maxn], rlen;

void Update(int v, int l, int r, int x, ii val)
{
	if (l == r) mn[v] = val;
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, val);
		else Update(2 * v + 1, m + 1, r, x, val);
		mn[v] = mn[2 * v] < mn[2 * v + 1]? mn[2 * v]: mn[2 * v + 1];
	}
}

ii Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return mn[v];
	else {
		ii res = ii(Inf, -1), cand;
		int m = l + r >> 1;
		if (a <= m) {
			cand = Get(2 * v, l, m, a, min(m, b));
			if (cand < res) res = cand;
		}
		if (m + 1 <= b) {
			cand = Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
			if (cand < res) res = cand;
		}
		return res;
	}
}

void Clear()
{
	for (int i = 0; i < tlen; i++) {
		fir[tmp[i]] = -1; lst[tmp[i]] = -1; cnt[tmp[i]] = -1;
	}
	tlen = 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		un.push_back(a[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < un.size(); i++) {
		fir[i] = -1; lst[i] = -1; cnt[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
		if (lst[a[i]] == -1) {
			fir[a[i]] = i; lst[a[i]] = i; cnt[a[i]] = 1;
			tmp[tlen++] = a[i];
			Update(1, 0, n - 1, i, ii(Inf, a[i]));
		} else {
			int f = fir[a[i]], l = lst[a[i]], c = ++cnt[a[i]]; lst[a[i]] = i;
			if (c == 4) {
				while (c--) res[rlen++] = a[i];
				Clear(); continue;
			} else if (l + 1 <= i - 1) {
				ii cand = Get(1, 0, n - 1, l + 1, i - 1);
				if (cand.first < l) {
					res[rlen++] = cand.second;
					res[rlen++] = a[i];
					res[rlen++] = cand.second;
					res[rlen++] = a[i];
					Clear(); continue;
				}
			}
			Update(1, 0, n - 1, i, ii(fir[a[i]], a[i]));
		}
	}
	printf("%d\n", rlen);
	for (int i = 0; i < rlen; i++)
		printf("%d%c", un[res[i]], i + 1 < rlen? ' ': '\n');
	return 0;
}