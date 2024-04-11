#include <cstdio>
#include <vector>
#include <queue>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> rneigh[Maxn], neigh[Maxn];
int in[Maxn];
vector <int> seq;
bool tk[Maxn], tk2[Maxn];
int res;

void Traverse(int v)
{
	if (tk[v]) return;
	tk[v] = true; seq.push_back(v);
	for (int i = 0; i < rneigh[v].size(); i++)
		Traverse(rneigh[v][i]);
}

int Solve()
{
	queue <int> Q;
	for (int i = 0; i < seq.size(); i++)
		if (in[seq[i]] == 0) { Q.push(seq[i]); tk2[seq[i]] = true; }
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (--in[u] == 0) { Q.push(u); tk2[u] = true; }
		}
	}
	for (int i = 0; i < seq.size(); i++)
		if (!tk2[seq[i]]) return seq.size();
	return seq.size() - 1;
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); in[b]++;
		rneigh[a].push_back(b); rneigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (!tk[i]) {
		seq.clear();
		Traverse(i);
		res += Solve();
	}
	printf("%d\n", res);
	return 0;
}