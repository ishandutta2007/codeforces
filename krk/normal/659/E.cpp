#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
int tk[Maxn];
int res;

int Fill(int v, int p, bool &loop)
{
    if (tk[v] == 2) return 0;
    if (tk[v] == 1) { loop = true; return 0; }
    tk[v] = 1;
    int res = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        res += Fill(u, v, loop);
    }
    tk[v] = 2;
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!tk[i]) {
        bool loop = false;
        int got = Fill(i, 0, loop);
        if (got == 1 || got > 1 && !loop)
            res++;
    }
    printf("%d\n", res);
	return 0;
}