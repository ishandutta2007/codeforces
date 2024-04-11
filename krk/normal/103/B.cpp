#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int Maxn = 105;

int n, m;
bool edge[Maxn][Maxn];
bool taken[Maxn];
bool rec;
int swoff;
vector <int> cycl;

void findCycle(int v, int p)
{
     taken[v] = true;
     for (int i = 1; i <= n && !rec; i++)
        if (i != p && edge[v][i])
           if (taken[i]) { rec = true; swoff = i; }
           else findCycle(i, v);
     if (rec) {
              cycl.push_back(v);
              if (v == swoff) rec = false;
     }
}

bool isTree(int v, int p)
{
     if (taken[v]) return false;
     taken[v] = true;
     for (int i = 1; i <= n; i++)
        if (i != p && edge[v][i])
           if (!isTree(i, v)) return false;
     return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        edge[a][b] = edge[b][a] = true;
    }
    findCycle(1, -1);
    if (cycl.size() < 3) cout << "NO\n";
    else {
         for (int i = 0; i < cycl.size(); i++)
            edge[cycl[i]][cycl[(i + 1) % cycl.size()]] = 
            edge[cycl[(i + 1) % cycl.size()]][cycl[i]] = 0;
         fill(taken, taken + n + 1, false);
         int i;
         for (i = 0; i < cycl.size(); i++)
            if (!isTree(cycl[i], -1)) break;
         if (i < cycl.size()) cout << "NO\n";
         else {
              for (i = 1; i <= n; i++)
                 if (!taken[i]) break;
              if (i <= n) cout << "NO\n";
              else cout << "FHTAGN!\n";
         }
    }
    return 0;
}