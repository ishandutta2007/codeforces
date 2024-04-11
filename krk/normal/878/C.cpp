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

const int Maxn = 50005;
const int Maxk = 10;

int n, k;
int par[Maxn], siz[Maxn];
int mn[Maxn][Maxk], mx[Maxn][Maxk];

struct pos {
	int x;
	pos(int x = 0): x(x) {}
	bool operator <(const pos &b) const {
		bool less = true;
		for (int i = 0; i < k; i++)
			if (mx[x][i] >= mn[b.x][i]) less = false;
		return less;
	}
};
set <pos> S; 

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b]; par[b] = a;
	for (int j = 0; j < k; j++) {
		mn[a][j] = min(mn[a][j], mn[b][j]);
		mx[a][j] = max(mx[a][j], mx[b][j]);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		par[i] = i; siz[i] = 1;
		for (int j = 0; j < k; j++) {
			int a; scanf("%d", &a);
			mn[i][j] = mx[i][j] = a;
		}
		set <pos>::iterator it = S.lower_bound(pos(i)), it2 = S.upper_bound(pos(i));
		while (it != it2) {
			int g = it->x; S.erase(it++);
			unionSet(i, g);
		}
		S.insert(pos(getPar(i)));
		int leader = S.rbegin()->x;
		printf("%d\n", siz[leader]);
	}
	return 0;
}