#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n, m, k;
vector <int> neigh[Maxn];
int t, tim[Maxn];
vector <int> seq;
bool found;

void Search(int v)
{
	tim[v] = ++t; seq.push_back(v);
	for (int i = 0; i < neigh[v].size() && !found; i++) {
		int u = neigh[v][i];
		if (!tim[u]) Search(u);
		if (tim[v] - tim[u] >= k) {
			found = true;
			int res = tim[v] - tim[u] + 1;
			printf("%d\n", res);
			while (res--) {
				int a = seq.back(); seq.pop_back();
				printf("%d%c", a, res? ' ': '\n');
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	for (int i = 1; i <= n && !found; i++)
		if (!tim[i]) {
			seq.clear();
			Search(i);
		}
	return 0;
}