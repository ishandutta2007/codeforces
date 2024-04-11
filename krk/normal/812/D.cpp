#include <bits/stdc++.h>
using namespace std;
 
typedef pair <int, int> ii;
 
const int Maxn = 100005;
 
int n, m, k, q;
int A[Maxn], B[Maxn];
vector <int> neigh[Maxn];
int L[Maxn], cnt[Maxn];
int cur, lef[Maxn], rig[Maxn];

void Solve(int v)
{
	cnt[v] = 1;
	lef[v] = ++cur;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		L[u] = L[v] + 1;
		Solve(u);
		cnt[v] += cnt[u];
	}
	rig[v] = cur;
}
 
int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (int i = 0; i < k; i++) {
		int a, b; scanf("%d %d", &a, &b);
		if (A[b] != 0) { B[a] = A[b]; neigh[A[b]].push_back(a); }
		A[b] = a;
	}
	for (int i = 1; i <= n; i++) if (B[i] == 0)
		Solve(i);
	while (q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (A[y] != 0) {
			int v = A[y];
			if (lef[x] <= lef[v] && lef[v] <= rig[x]) printf("%d\n", cnt[x]);
			else printf("0\n");
		} else printf("0\n");
	}
    return 0;
}