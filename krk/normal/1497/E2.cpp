#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 10000005;
const int Maxs = 1048576;
const int Inf = 1000000000;

vector <int> pr;
int dv[Maxm];
int T;
int n, k;
map <int, int> M;
int fl[Maxs];
vector <int> st[Maxs];

void Create(int v, int l, int r)
{
	fl[v] = 0;
	st[v].resize(k + 1);
	fill(st[v].begin(), st[v].end(), Inf);
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m);
		Create(2 * v + 1, m + 1, r);
	}
}

void downOn(int v, int f)
{
	fl[v] += f;
	for (int i = k; i >= 0; i--) {
		if (i + f <= k)
			st[v][i + f] = st[v][i];
		st[v][i] = Inf;
	}
}

void Down(int v)
{
	if (fl[v]) {
		downOn(2 * v, fl[v]);
		downOn(2 * v + 1, fl[v]);
		fl[v] = 0;
	}
}

void Union(int v)
{
	int lc = 2 * v, rc = 2 * v + 1;
	for (int i = 0; i <= k; i++)
		st[v][i] = min(st[lc][i], st[rc][i]);
}

void Rotate(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) downOn(v, 1);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Rotate(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) Rotate(2 * v + 1, m + 1, r, max(m + 1, a), b);
		Union(v);
	}
}

void Get(int v, int l, int r, int a, int b, vector <int> &res)
{
	if (l == a && r == b)
		for (int i = 0; i <= k; i++)
			res[i] = min(res[i], st[v][i]);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Get(2 * v, l, m, a, min(m, b), res);
		if (m + 1 <= b) Get(2 * v + 1, m + 1, r, max(m + 1, a), b, res);
	}
}

void Insert(int v, int l, int r, int x, const vector <int> &vals)
{
	if (l == r)
		for (int i = 0; i <= k; i++)
			st[v][i] = vals[i];
	else {
		Down(v);
		int m = l + r >> 1;
		if (x <= m) Insert(2 * v, l, m, x, vals);
		else Insert(2 * v + 1, m + 1, r, x, vals);
		Union(v);
	}
}

vector <int> Get(int a, int b)
{
	vector <int> tmp(k + 1, Inf);
	Get(1, 0, n - 1, a, b, tmp);
	return tmp;
}

int main()
{
	for (int i = 2; i < Maxm; i++) {
		if (dv[i] == 0) { dv[i] = i; pr.push_back(i); }
		for (int j = 0; j < pr.size() && pr[j] * i < Maxm; j++) {
			dv[pr[j] * i] = pr[j];
			if (i % pr[j] == 0) break;
		}
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		M.clear();
		Create(1, 0, n - 1);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			int got = 1;
			while (a > 1) {
				int cur = dv[a], cnt = 0;
				while (a % cur == 0) { a /= cur; cnt++; }
				if (cnt % 2) got *= cur;
			}
			if (M.find(got) != M.end()) {
				int lst = M[got];
				auto my = Get(0, lst);
				for (int i = 0; i <= k; i++)
					my[i]++;
				Insert(1, 0, n - 1, i, my);
				Rotate(1, 0, n - 1, 0, lst);
			} else if (i == 0) {
				vector <int> my(k + 1, 1);
				Insert(1, 0, n - 1, i, my);
			}
			M[got] = i;
		}
		auto my = Get(0, n - 1);
		printf("%d\n", my[k]);
	}
    return 0;
}