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
using namespace std;

const int Maxn = 300005;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
map <int, int> M;
int res = 2000000007;

void Add(int x) { M[x]++; }

void Rem(int x) { if (--M[x] == 0) M.erase(x); }

int Get() { return M.empty()? -2000000007: M.rbegin()->first; }

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		Add(a[i] + 2);
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		Rem(a[i] + 2);
		int cur = a[i];
		for (int j = 0; j < neigh[i].size(); j++) {
			Rem(a[neigh[i][j]] + 2);
			cur = max(cur, a[neigh[i][j]] + 1);
		}
		res = min(res, max(cur, Get()));
		for (int j = 0; j < neigh[i].size(); j++)
			Add(a[neigh[i][j]] + 2);
		Add(a[i] + 2);
	}
	printf("%d\n", res);
	return 0;
}