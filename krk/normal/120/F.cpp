#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, b;
vector <int> neigh[Maxn];
int curres;
int res;

int getBest(int v, int p)
{
    int res = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        res = max(res, getBest(u, v) + 1);
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
          cin >> b;
          for (int i = 1; i <= b; i++) neigh[i].clear();
          curres = 0;
          for (int i = 0; i < b - 1; i++) {
              int u, v; cin >> u >> v;
              neigh[u].push_back(v); neigh[v].push_back(u);
          }
          for (int i = 1; i <= b; i++)
             curres = max(curres, getBest(i, 0));
          res += curres;
    }
    cout << res << endl;
    return 0;
}