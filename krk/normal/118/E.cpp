#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

const int Maxn = 100005;
const int Maxm = 300005;

int n, m;
int a[Maxm], b[Maxm];
vector <int> neigh[Maxn];
vector <int> to[Maxn], from[Maxn];
int taken[Maxn];
int no;
vector <pair <int, int> > V;

void Search(int v, int p)
{
     if (taken[v]) return;
     taken[v] = ++no;
     if (p) { to[p].push_back(v); from[v].push_back(p); }
     for (int i = 0; i < neigh[v].size(); i++) {
         int u = neigh[v][i];
         if (u == p) continue;
         if (taken[u]) {
                       if (taken[u] < taken[v]) {
                                    to[v].push_back(u);
                                    from[u].push_back(v);
                       }
         } else Search(u, v);
     }
}

void Search(int v)
{
     if (taken[v]) return;
     taken[v] = true;
     for (int i = 0; i < from[v].size(); i++) 
         Search(from[v][i]);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        neigh[a[i]].push_back(b[i]);
        neigh[b[i]].push_back(a[i]);
    }
    Search(1, 0);
    fill(taken, taken + Maxn, 0);
    Search(1);
    int i;
    for (i = 1; i <= n; i++)
        if (!taken[i]) break;
    if (i <= n) printf("0\n");
    else for (int i = 1; i <= n; i++)
             for (int j = 0; j < to[i].size(); j++)
                 printf("%d %d\n", i, to[i][j]);
    return 0;
}