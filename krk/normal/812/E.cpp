#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];
map <int, int> M;
vector <int> neigh[Maxn];
int L[Maxn], mx;
ll res;

void Traverse(int v)
{
	mx = max(mx, L[v]);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		L[u] = L[v] + 1; Traverse(u);
	}
}

int Get(int x)
{
	map <int, int>::iterator it = M.find(x);
	return it == M.end()? 0: it->second;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
	}
	Traverse(1);
	int my = 0, cnta = 0, cntb = 0;
	for (int i = 1; i <= n; i++)
		if (L[i] % 2 != mx % 2) { M[a[i]]++; cnta++; }
		else { my ^= a[i]; cntb++; }
	if (my == 0)
		res += ll(cnta) * (cnta - 1) / 2 + ll(cntb) * (cntb - 1) / 2;
	for (int i = 1; i <= n; i++)
		if (L[i] % 2 == mx % 2) res += Get(my ^ a[i]);
	printf("%I64d\n", res);
	return 0;
}