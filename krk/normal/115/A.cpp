#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 2005;

int n;
vector <int> neigh[Maxn];
bool taken[Maxn];
int res;

void Fill(int v, int lvl)
{
     if (taken[v]) return;
     taken[v] = true;
     res = max(res, lvl);
     for (int i = 0; i < neigh[v].size(); i++)
        Fill(neigh[v][i], lvl + 1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        if (p != -1) neigh[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        fill(taken, taken + Maxn, false);
        Fill(i, 1);
    }
    cout << res << endl;
    return 0;
}