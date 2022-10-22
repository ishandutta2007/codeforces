#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int mod = 1000000007;

int n;
vector <int> neigh[Maxn];
int ch[Maxn][2];

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i]);

	int cur[2] = {0, 1};
	int ncur[2];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		ncur[0] = (cur[0] + ll(cur[0]) * ch[u][0] + ll(cur[1]) * ch[u][1]) % mod;
		ncur[1] = (cur[1] + ll(cur[1]) * ch[u][0] + ll(cur[0]) * ch[u][1]) % mod;
		cur[0] = ncur[0]; cur[1] = ncur[1];
	}
	ch[v][0] = cur[0]; ch[v][1] = cur[1];

	cur[0] = 0; cur[1] = 1;
	for (int i = int(neigh[v].size() - 1); i >= 0; i--) {
		int u = neigh[v][i];
		ncur[0] = (cur[0] + ll(cur[0]) * ch[u][0] + ll(cur[1]) * ch[u][1]) % mod;
		ncur[1] = (cur[1] + ll(cur[1]) * ch[u][0] + ll(cur[0]) * ch[u][1]) % mod;
		cur[0] = ncur[0]; cur[1] = ncur[1];
	}
	ch[v][0] = (ch[v][0] + cur[0]) % mod; ch[v][1] = (ch[v][1] + cur[1]) % mod;

	// change not
	cur[1] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		cur[1] = ll(cur[1]) * (ch[u][0] + 1) % mod;
	}
	ch[v][1] = (ch[v][1] - cur[1] + mod) % mod;

	// change
	cur[0] = 0; cur[1] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		ncur[0] = (cur[0] + ll(cur[1]) * ch[u][1]) % mod;
		ncur[1] = (cur[1] + ll(cur[0]) * ch[u][1]) % mod;
		cur[0] = ncur[0]; cur[1] = ncur[1];
	}
	ch[v][0] = (ch[v][0] - cur[0] + mod) % mod;
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		sort(neigh[i].begin(), neigh[i].end());
	Traverse(1);
	printf("%d\n", (ch[1][0] + ch[1][1]) % mod);
	return 0;
}