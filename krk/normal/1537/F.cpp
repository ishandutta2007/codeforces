#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, m;
int A[Maxn];
int B[Maxn];
vector <int> neigh[Maxn];
int tk[Maxn];
ll nd[Maxn];

bool Bic(int v, int c)
{
	if (tk[v]) return tk[v] == c;
	tk[v] = c;
	for (int i = 0; i < neigh[v].size(); i++)
		if (!Bic(neigh[v][i], -c)) return false;
	return true;
}

bool Solve()
{
	if (Bic(1, 1)) {
		ll sum = 0;
		for (int i = 1; i <= n; i++)
			sum += nd[i] * tk[i];
		return sum == 0;
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		sum += nd[i];
	return sum % 2 == 0;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &B[i]);
		for (int i = 1; i <= n; i++) {
			neigh[i].clear();
			tk[i] = 0;
			nd[i] = B[i] - A[i];
		}
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			neigh[a].push_back(b);
			neigh[b].push_back(a);
		}
		printf("%s\n", Solve()? "YES": "NO");
	}
    return 0;
}