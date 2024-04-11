#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Inf = 1000000000;
const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn], back[Maxn];
int len;
int col[Maxn];
int best;

void Color(int v, int c)
{
	if (col[v] != Inf) {
		if (col[v] != c) len = abs(c - col[v]);
		return;
	}
	col[v] = c;
	for (int i = 0; i < neigh[v].size() && !len; i++) {
		int u = neigh[v][i];
		Color(u, c + 1);
	}
	for (int i = 0; i < back[v].size() && !len; i++) {
		int u = back[v][i];
		Color(u, c - 1);
	}
}

bool canColor(int v, int c, int k)
{
	if (col[v] != -1) return col[v] == c;
	col[v] = c;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (!canColor(u, (c + 1) % k, k)) return false;
	}
	for (int i = 0; i < back[v].size(); i++) {
		int u = back[v][i];
		if (!canColor(u, (c - 1 + k) % k, k)) return false;
	}
	return true;
}

bool Test(int k)
{
	fill(col, col + n + 1, -1);
	for (int i = 1; i <= n; i++) if (col[i] == -1)
		if (!canColor(i, 0, k)) return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); back[b].push_back(a);
	}
	fill(col, col + n + 1, Inf);
	for (int i = 1; i <= n && !len; i++) if (col[i] == Inf)
		Color(i, 0);
	if (len == 0) { printf("%d\n", n); return 0; }
	for (int i = 1; i * i <= len; i++)
		if (len % i == 0) {
			if (i > best) { if (Test(i)) best = i; }
			if (len / i > best) { if (Test(len / i)) best = len / i; }
		}
	printf("%d\n", best);
	return 0;
}