#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;

int T;
int n;
char A[Maxn][Maxn];
char B[Maxn][Maxn];
vector <ii> neigh[Maxn];
int col[Maxn];

bool Solve(int v, int c)
{
	if (col[v] == c) return true;
	if (col[v] != 0) return false;
	col[v] = c;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (!Solve(u.first, u.second == 1? -c: c))
			return false;
	}
	return true;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < 2 * n; i++) {
			neigh[i].clear();
			col[i] = 0;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf(" %c", &A[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf(" %c", &B[i][j]);
				int val = ((A[i][j] == '1') ^ (B[i][j] == '1'));
				neigh[i].push_back(ii(n + j, val));
				neigh[n + j].push_back(ii(i, val));
			}
		if (Solve(0, 1)) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}