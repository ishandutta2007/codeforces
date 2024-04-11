#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxn = 305;

int n, c, e;
int a[Maxn];
int b[Maxn];
bool R[Maxn][Maxn];
bool t1[Maxn], t2[Maxn], del[Maxn];
vector <int> x, y, d;

ll getStatus(int v)
{
	t1[v] = true;
	ll st = a[v] - b[v];
	for (int i = 1; i <= n; i++)
		if (R[v][i] && !t1[i]) st += getStatus(i);
	return st;
}

bool Possible()
{
	for (int i = 1; i <= n; i++) if (!t1[i])
		if (getStatus(i)) return false;
	return true; 
}

void fillBucket(int v, bool root)
{
	t2[v] = true;
	for (int i = 1; i <= n; i++)
		if (R[v][i] && !t2[i] && !del[i]) {
			fillBucket(i, false);
			int tr = root? min(b[v] - a[v], a[i]): min(c - a[v], a[i]);
			x.push_back(i); y.push_back(v); d.push_back(tr);
			a[v] += tr; a[i] -= tr;
		}
}

void spilBucket(int v, bool root)
{
	t2[v] = true;
	for (int i = 1; i <= n; i++)
		if (R[v][i] && !t2[i] && !del[i]) {
			spilBucket(i, false);
			int tr = root? min(a[v] - b[v], c - a[i]): min(a[v], c - a[i]);
			x.push_back(v); y.push_back(i); d.push_back(tr);
			a[v] -= tr; a[i] += tr;
		}
}

void Dfs(int v)
{
	t1[v] = true;
	for (int i = 1; i <= n; i++)
		if (R[v][i] && !t1[i]) Dfs(i);
	fill(t2 + 1, t2 + n + 1, false);
	if (a[v] < b[v]) fillBucket(v, true);
	else if (a[v] > b[v]) spilBucket(v, true);
	del[v] = true;
}

int main()
{
	scanf("%d %d %d", &n, &c, &e);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	while (e--) {
		int u, v; scanf("%d %d", &u, &v);
		R[u][v] = R[v][u] = true;
	}
	if (!Possible()) printf("NO\n");
	else {
		fill(t1 + 1, t1 + n + 1, false);
		for (int i = 1; i <= n; i++) if (!t1[i])
			Dfs(i);
		printf("%d\n", x.size());
		for (int i = 0; i < x.size(); i++)
			printf("%d %d %d\n", x[i], y[i], d[i]);
	}
	return 0;
}