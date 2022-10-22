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
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 1000005;

int n;
int sum;
int t[Maxn];
int my[Maxn];
vector <int> neigh[Maxn];
int root;
vector <int> res;

void Traverse(int v)
{
	my[v] = t[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		Traverse(u); my[v] += my[u];
	}
	if (my[v] == sum / 3 && v != root) { res.push_back(v); my[v] = 0; }
}

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int p; scanf("%d %d", &p, &t[i]); sum += t[i];
		if (p > 0) neigh[p].push_back(i);
		else root = i;
	}
	if (sum % 3 != 0) { printf("-1\n"); return 0; }
	Traverse(root);
	if (res.size() < 2) printf("-1\n");
	else printf("%d %d\n", res[0], res[1]);
    return 0;
}