#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;
const int Maxm = 8192;

struct node {
	short lef, rig, cnt, mx;
};

int n, m, k;
node st[Maxn][Maxm];
char B[Maxn][Maxn];
int qx[Maxn], qy[Maxn];
int mx[Maxn][Maxn];
vector <ii> seq[Maxn];
int nd = 1;
int res[Maxn];

void Union(int t, int v)
{
	int lc = 2 * v, rc = 2 * v + 1;
	st[t][v].mx = max(st[t][lc].mx, st[t][rc].mx);
	st[t][v].mx = max(st[t][v].mx, (short)(st[t][lc].rig + st[t][rc].lef));
	st[t][v].cnt = st[t][lc].cnt + st[t][rc].cnt;
	st[t][v].lef = st[t][lc].lef == st[t][lc].cnt? st[t][lc].lef + st[t][rc].lef: st[t][lc].lef;
	st[t][v].rig = st[t][rc].rig == st[t][rc].cnt? st[t][rc].rig + st[t][lc].rig: st[t][rc].rig;
}

void Create(int t, int v, int l, int r)
{
	st[t][v].lef = st[t][v].rig = st[t][v].mx = 0;
	st[t][v].cnt = r - l + 1;
	if (l < r) {
		int m = l + r >> 1;
		Create(t, 2 * v, l, m);
		Create(t, 2 * v + 1, m + 1, r);
	}
}

void Update(int t, int v, int l, int r, int x, int val)
{
	if (l == r) {
		st[t][v].lef = st[t][v].rig = st[t][v].mx = val;
		st[t][v].cnt = 1;
	} else {
		int m = l + r >> 1;
		if (x <= m) Update(t, 2 * v, l, m, x, val);
		else Update(t, 2 * v + 1, m + 1, r, x, val);
		Union(t, v);
	}
}

void Update(int r, int c, int val)
{
	if (val < nd) { mx[r][c] = val; return; }
	if (mx[r][c] < nd) Update(c, 1, 0, n - 1, r, 1);
	mx[r][c] = val;
	seq[val].push_back(ii(r, c));
}

void Improve()
{
	bool cont = true;
	while (cont) {
		cont = false;
		for (int j = 0; j < m; j++)
			if (st[j][1].mx >= nd) {
				cont = true;
				break;
			}
		if (!cont) break;
		for (int j = 0; j < seq[nd].size(); j++) {
			ii p = seq[nd][j];
			if (mx[p.first][p.second] == nd)
				Update(p.second, 1, 0, n - 1, p.first, 0);
		}
		nd++;
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int j = 0; j < m; j++)
		Create(j, 1, 0, n - 1);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &qx[i], &qy[i]);
		qx[i]--; qy[i]--;
		B[qx[i]][qy[i]] = 'X';
	}
	for (int i = 0; i < n; i++)
		for (int j = m - 1; j >= 0; j--) {
			int num = B[i][j] == 'X'? 0: mx[i][j + 1] + 1;
			Update(i, j, num);
		}
	for (int i = k - 1; i >= 0; i--) {
		Improve();
		res[i] = nd - 1;
		B[qx[i]][qy[i]] = '.';
		for (int j = qy[i]; j >= 0 && B[qx[i]][j] != 'X'; j--) {
			int num = 1 + mx[qx[i]][j + 1];
			Update(qx[i], j, num);
		}
	}
	for (int i = 0; i < k; i++)
		printf("%d\n", res[i]);
    return 0;
}