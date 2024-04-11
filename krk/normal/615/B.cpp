#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
int res[Maxn];
ll best;

int Get(int v)
{
	if (res[v] == -1) {
		res[v] = 1;
		for (int i = 0; i < neigh[v].size(); i++)
			if (neigh[v][i] < v) res[v] = max(res[v], 1 + Get(neigh[v][i]));
	}
	return res[v];
}

int main() 
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	fill(res, res + Maxn, -1);
	for (int i = 1; i <= n; i++)
		best = max(best, ll(neigh[i].size()) * Get(i));
	cout << best << endl;
    return 0;
}