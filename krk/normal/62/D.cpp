#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 101;
const int Maxm = 2002;

int n, m, pth[Maxm], gen[Maxm];
vector <int> neigh[Maxn];
bool taken[Maxn][Maxn];
int ans;

void Generate(int lvl)
{
     int v = gen[lvl];
     if (lvl == m) {
             if (v == pth[0]) ans++;
     } else {
            int ind;
            if (ans == 0) 
               ind = lower_bound(neigh[v].begin(), neigh[v].end(), pth[lvl+1]) - neigh[v].begin();
            else ind = 0;
            for (int i = ind; i < neigh[v].size() && ans < 2; i++) 
               if (!taken[v][neigh[v][i]]) {
                                           taken[v][neigh[v][i]] = taken[neigh[v][i]][v] = true;
                                           gen[lvl+1] = neigh[v][i];
                                           Generate(lvl+1);
                                           taken[v][neigh[v][i]] = taken[neigh[v][i]][v] = false;
               }
     }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i <= m; i++) {
        cin >> pth[i];
        if (i) {
               neigh[pth[i-1]].push_back(pth[i]);
               neigh[pth[i]].push_back(pth[i-1]);
        }
    }
    for (int i = 0; i <= n; i++) sort(neigh[i].begin(), neigh[i].end());
    gen[0] = pth[0];
    Generate(0);
    if (ans < 2) cout << "No solution\n";
    else for (int i = 0; i <= m; i++) {
            cout << gen[i];
            if (i < m) cout << " ";
            else cout << endl;
         }
    return 0;
}