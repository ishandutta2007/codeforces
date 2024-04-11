#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;

int t;
int n, m;
bool E[Maxn][Maxn];
int deg[Maxn];
int tot;
bool tk[Maxn];
vector <int> S;
vector <int> pth;

void Fill(int v)
{
	while (true)
		if (deg[v] == 0) {
			pth.push_back(v);
			if (S.empty()) return;
			v = S.back(); S.pop_back();
		} else {
			S.push_back(v);
			int u = 1;
			while (!E[v][u]) u++;
			E[v][u] = E[u][v] = false; deg[v]--; deg[u]--;
			v = u;
			if (deg[v] % 2 == 0) {
				S.push_back(v);
				while (!S.empty()) {
					pth.push_back(S.back());
					S.pop_back();
				}
				return;
			}
		}

}

void Print()
{
	for (int i = 0; i + 1 < pth.size(); i++)
		printf("%d %d\n", pth[i], pth[i + 1]);
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		tot = 0;
		for (int i = 1; i <= n; i++) {
			deg[i] = 0; tk[i] = false;
			for (int j = 1; j <= n; j++)
				E[i][j] = false;
		}
		while (m--) {
			int a, b; scanf("%d %d", &a, &b);
			E[a][b] = E[b][a] = true;
			deg[a]++; deg[b]++;
		}
		for (int i = 1; i <= n; i++)
			tot += deg[i] % 2 == 0;
		printf("%d\n", tot);
		for (int i = 1; i <= n; i++) if (deg[i] % 2 == 1) {
			S.clear();
			Fill(i);
			Print(); pth.clear();
		}
		for (int i = 1; i <= n; i++) if (deg[i] > 0) {
			S.clear();
			Fill(i);
			Print(); pth.clear();
		}
	}
	return 0;
}