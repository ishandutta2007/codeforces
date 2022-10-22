#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 5005;

int n;
char neigh[Maxn][Maxn];
int taken[Maxn], p[Maxn];
vector <int> res;

void tryGet(int v, int par)
{
     taken[v] = 1; p[v] = par;
     for (int i = 0; res.empty() && i < n; i++)
         if (neigh[v][i] == '1')
            if (taken[i] == 1) {
                         res.push_back(i);
                         while (v != i) {
                               res.push_back(v);
                               v = p[v];
                         }
            } else if (!taken[i]) tryGet(i, v);
     taken[v] = 2;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", neigh[i]);
    for (int i = 0; i < n && res.empty(); i++)
        if (!taken[i]) tryGet(i, -1);
    if (res.empty()) cout << "-1\n";
    else {
         while (neigh[res[0]][res[res.size() - 2]] == '1') res.pop_back();
         cout << res.back() + 1 << " " << res[res.size() - 2] + 1 << " " << res[0] + 1 << endl; 
    }
    return 0;
}