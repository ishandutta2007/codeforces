#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxn = 1005;

int n, m, k;
int x[Maxn], y[Maxn];
int r[Maxn], Cx[Maxn], Cy[Maxn];
vector <int> neigh[Maxn];

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for (int i = 0; i < m; i++)
        cin >> r[i] >> Cx[i] >> Cy[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (ll(x[i] - Cx[j]) * ll(x[i] - Cx[j]) + 
                ll(y[i] - Cy[j]) * ll(y[i] - Cy[j]) < ll(r[j]) * ll(r[j])) 
                neigh[i].push_back(j);
    while (k--) {
          int a, b; cin >> a >> b; a--; b--;
          int i = 0, j = 0;
          int res = 0;
          while (i < neigh[a].size() && j < neigh[b].size())
                if (neigh[a][i] < neigh[b][j]) { res++; i++; }
                else if (neigh[a][i] > neigh[b][j]) { res++; j++; }
                else { i++; j++; }
          res += neigh[a].size() - i + neigh[b].size() - j;
          cout << res << endl;
    }
    return 0;
}