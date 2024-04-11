#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxp = 320;
const int Maxm = 524288;

int n;
int b[Maxn];
int nxtbyval[Maxn];
int nxt[Maxn];
int prvbyval[Maxn];
deque <int> seq[Maxn];
vector <ii> st[Maxm];
int dif;
int cnt[Maxn];
int q;
int qa[Maxn], qb[Maxn];
vector <ii> bylef[Maxp];
int res[Maxn];

void Update(int v, int l, int r, int a, int b, int lef, int rig)
{
	if (l == a && r == b) {
		while (!st[v].empty() && lef <= st[v].back().first)
			st[v].pop_back();
		if (!st[v].empty() && lef <= st[v].back().second + 1) st[v].back().second = rig;
		else st[v].push_back(ii(lef, rig)); 
	} else {
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), lef, rig);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, lef, rig);
	}
}

bool Get(int v, int l, int r, int x, int y)
{
	int ind = lower_bound(st[v].begin(), st[v].end(), ii(y + 1, 0)) - st[v].begin() - 1;
	if (ind >= 0 && y <= st[v][ind].second) return true;
	if (l == r) return false;
	else {
		int m = l + r >> 1;
		if (x <= m) return Get(2 * v, l, m, x, y);
		else return Get(2 * v + 1, m + 1, r, x, y);
	}
}

void Add(int ind)
{
	if (cnt[b[ind]]++ == 0) dif++;
}

void Rem(int ind)
{
	if (--cnt[b[ind]] == 0) dif--;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	fill(nxtbyval, nxtbyval + Maxn, n + 1);
	for (int i = n; i > 0; i--) {
		nxt[i] = nxtbyval[b[i]];
		nxtbyval[b[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		seq[b[i]].push_back(i);
		while (seq[b[i]].size() >= 2 && seq[b[i]][1] - seq[b[i]].front() != seq[b[i]].back() - seq[b[i]][int(seq[b[i]].size()) - 2]) {
			prvbyval[b[i]] = seq[b[i]].front();
			seq[b[i]].pop_front();
		}
		Update(1, 1, n, i, nxt[i] - 1, prvbyval[b[i]] + 1, i);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &qa[i], &qb[i]);
		if (qb[i] - qa[i] <= Maxp) {
			for (int j = qa[i]; j <= qb[i]; j++)
				Add(j);
			res[i] = dif;
			for (int j = qa[i]; j <= qb[i]; j++)
				Rem(j);
		} else bylef[qa[i] / Maxp + 1].push_back(ii(qb[i], i));
	}
	for (int i = 0; i < Maxp; i++) {
		sort(bylef[i].begin(), bylef[i].end());
		int L = i * Maxp, R = i * Maxp;
		for (int j = 0; j < bylef[i].size(); j++) {
			int ind = bylef[i][j].second;
			while (R <= qb[ind]) Add(R++);
			while (qa[ind] < L) Add(--L);
			while (L < qa[ind]) Rem(L++);
			res[ind] = dif;
		}
		while (L < R) Rem(L++);
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", res[i] + 1 - int(Get(1, 1, n, qb[i], qa[i])));
    return 0;
}