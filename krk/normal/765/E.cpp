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

const int Maxn = 200005;

int n;
set <int> neigh[Maxn];
set <int> S[Maxn];
bool tk[Maxn];
vector <int> seq;

int getRes(int x) { return x % 2 == 0? getRes(x / 2): x; }

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].insert(b);
		neigh[b].insert(a);
	}
	for (int i = 1; i <= n; i++)
		if (neigh[i].size() <= 1) { tk[i] = true; seq.push_back(i); }
	for (int i = 0; i < seq.size(); i++) {
		int v = seq[i];
		if (i == n - 1) {
			if (S[v].size() > 2) continue;
			int sum = 0;
			for (set <int>::iterator it = S[v].begin(); it != S[v].end(); it++)
				sum += *it;
			printf("%d\n", getRes(sum)); return 0;
		}
		if (S[v].size() > 1) continue;
		int my = S[v].empty()? 0: *S[v].begin();
		for (set <int>::iterator it = neigh[v].begin(); it != neigh[v].end(); it++) {
			int u = *it;
			neigh[u].erase(v); S[u].insert(my + 1);
			if (!tk[u] && neigh[u].size() <= 1 && (S[u].size() <= 1 || seq.size() == n - 1)) { tk[u] = true; seq.push_back(u); }
		}
		neigh[v].clear();
	}
	printf("-1\n");
    return 0;
}