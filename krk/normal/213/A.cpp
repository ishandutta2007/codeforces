#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int Maxn = 205;
const int Maxh = 3;

int n;
int c[Maxn];
int deg[Maxn];
int cur[Maxn];
vector <int> fre[Maxn];
queue <int> Q[Maxh];

int getRes(int wh)
{
	for (int i = 1; i <= n; i++) {
		cur[i] = deg[i];
		if (!cur[i]) Q[c[i]].push(i);
	}
	int res = 0;
	while (!Q[0].empty() || !Q[1].empty() || !Q[2].empty())
		if (!Q[wh].empty()) {
			int v = Q[wh].front(); Q[wh].pop();
			for (int i = 0; i < fre[v].size(); i++) {
				int u = fre[v][i];
				if (--cur[u] == 0) Q[c[u]].push(u);
			}
		} else if (!Q[(wh + 1) % Maxh].empty()) { wh = (wh + 1) % Maxh; res++; }
			   else { wh = (wh - 1 + Maxh) % Maxh; res += 2; }
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]); c[i]--;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &deg[i]);
		for (int j = 0; j < deg[i]; j++) {
			int a; scanf("%d", &a);
			fre[a].push_back(i);
		}
	}
	printf("%d\n", n + min(min(getRes(0), getRes(1)), getRes(2)));
	return 0;
}