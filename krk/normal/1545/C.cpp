#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;
const int mod = 998244353;

int T;
int sz;
int n, m;
int B[Maxn][Maxn];
bool rem[Maxn];
set <int> col[Maxn][Maxn];
vector <int> neigh[Maxn];
vector <int> sol;

void getAll(int v, int st)
{
    if (rem[v]) return;
    if (st) sol.push_back(v);
    rem[v] = true;
    for (int i = 0; i < neigh[v].size(); i++)
        getAll(neigh[v][i], !st);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &sz);
        n = 2 * sz, m = sz;
        for (int j = 0; j < m; j++)
            for (int d = 0; d < sz; d++)
                col[j][d].clear();
        for (int i = 0; i < n; i++) {
            rem[i] = false;
            neigh[i].clear();
            for (int j = 0; j < m; j++){
                scanf("%d", &B[i][j]); B[i][j]--;
                col[j][B[i][j]].insert(i);
            }
        }
        sol.clear();
        queue <ii> Q;
        for (int j = 0; j < m; j++)
            for (int d = 0; d < sz; d++) if (col[j][d].size() == 1) {
                int ind = *col[j][d].begin();
                if (!rem[ind]) {
                    rem[ind] = true;
                    Q.push(ii(ind, 1));
                }
            }
        while (!Q.empty()) {
            int v = Q.front().first;
            int good = Q.front().second;
            if (good) sol.push_back(v);
            Q.pop();
            for (int j = 0; j < m; j++) {
                int d = B[v][j];
                col[j][d].erase(v);
                if (good) {
                    for (auto ind: col[j][d])
                        if (!rem[ind]) {
                            rem[ind] = true;
                            Q.push(ii(ind, 0));
                        }
                } else if (col[j][d].size() == 1) {
                    int ind = *col[j][d].begin();
                    if (!rem[ind]) {
                        rem[ind] = true;
                        Q.push(ii(ind, 1));
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) if (!rem[i])
            for (int j = i + 1; j < n; j++) if (!rem[j]) {
                int z = 0;
                while (z < m && B[i][z] != B[j][z]) z++;
                if (z < m) {
                    neigh[i].push_back(j);
                    neigh[j].push_back(i);
                }
            }
        int ways = 1;
        for (int i = 0; i < n; i++) if (!rem[i]) {
            ways = 2ll * ways % mod;
            getAll(i, true);
        }
        printf("%d\n", ways);
        for (int i = 0; i < sol.size(); i++)
            printf("%d%c", sol[i] + 1, i + 1 < sol.size()? ' ': '\n');
    }
    return 0;
}