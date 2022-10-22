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

const int Maxn = 30005;
const int Maxm = 4 * Maxn;
const int Maxk = 10;

int n, m;
int a[Maxm], b[Maxm], c[Maxm];
vector <int> joins[Maxn];
int my[Maxn];
set <int> cur[Maxk];
vector <int> res;

void Mod(int x, int val)
{
	cur[my[x]].erase(x);
	my[x] += val;
	if (!joins[x].empty())
		cur[my[x]].insert(x);
}

bool Step()
{
	for (int i = 0; i < Maxk; i++)
		if (!cur[i].empty()) {
			int v = *cur[i].begin();
			int ind = joins[v].back(); joins[v].pop_back();
			res.push_back(ind);
			Mod(b[ind], -1); Mod(c[ind], -1); Mod(a[ind], 1);
			return true;
		}
	return false;
}

int main()
{
	scanf("%d", &n); m = 4 * n;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		if (a[i] == b[i] && a[i] == c[i]) { res.push_back(i); my[a[i]]--; }
		else if (a[i] == b[i]) { res.push_back(i); my[c[i]]--; }
		else if (a[i] == c[i]) { res.push_back(i); my[b[i]]--; }
		else joins[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		my[i] += 8; 
		if (!joins[i].empty())
			cur[my[i]].insert(i);
	}
	while (Step()) ;
	printf("YES\n");
	for (int i = res.size() - 1; i >= 0; i--)
		printf("%d%c", res[i] + 1, i - 1 >= 0? ' ': '\n');
	return 0;
}