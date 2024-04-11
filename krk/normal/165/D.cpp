#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
vector <ii> neigh[Maxn];
int inbit[Maxn], h[Maxn], inbite[Maxn], he[Maxn];
vector <vector <int> > BIT;
int m;

int getLen(int v, int id, int p, int curh)
{
	inbit[v] = inbite[id] = BIT.size(); h[v] = he[id] = curh;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == p) continue;
		return getLen(u.first, u.second, v, curh + 1);
	}
	return curh;
}

void Add(vector <int> &BIT, int x, int val)
{
	for (int i = x; i < BIT.size(); i += i & -i)
		BIT[i] += val;
}

int Get(vector <int> &BIT, int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++) {
		int u, v; scanf("%d %d", &u, &v);
		neigh[u].push_back(ii(v, i)); neigh[v].push_back(ii(u, i));
	}
	int root = 1;
	while (root <= n && neigh[root].size() <= 2) root++;
	if (root > n) root = 1;
	for (int i = 0; i < neigh[root].size(); i++) {
		ii v = neigh[root][i];
		int len = getLen(v.first, v.second, root, 1);
		BIT.push_back(vector <int>(len + 1, 0));
	}
	scanf("%d", &m);
	while (m--) {
		int typ, a, b;
		scanf("%d", &typ);
		if (typ == 1) { scanf("%d", &a); Add(BIT[inbite[a]], he[a], -1); }
		else if (typ == 2) { scanf("%d", &a); Add(BIT[inbite[a]], he[a], 1); }
		else {
			scanf("%d %d", &a, &b);
			if (h[a] > h[b]) swap(a, b);
			if (inbit[a] == inbit[b])
				printf("%d\n", Get(BIT[inbit[b]], h[b]) - Get(BIT[inbit[a]], h[a]) == 0? h[b] - h[a]: -1);
			else printf("%d\n", Get(BIT[inbit[b]], h[b]) == 0 && Get(BIT[inbit[a]], h[a]) == 0? h[b] + h[a]: -1);
		}
	}
	return 0;
}