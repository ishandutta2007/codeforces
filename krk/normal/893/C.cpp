#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Inf = 2000000007;

int n, m; 
int c[Maxn];
vector <int> neigh[Maxn];
bool tk[Maxn];
ll res;

int Get(int v)
{
	if (tk[v]) return Inf;
	int res = c[v]; tk[v] = true;
	for (int i = 0; i < neigh[v].size(); i++)
		res = min(res, Get(neigh[v][i]));
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (!tk[i])
		res += Get(i);
	printf("%I64d\n", res);
	return 0;
}