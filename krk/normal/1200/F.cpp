#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;
const int Maxm = 2520;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
vector <ii> seq;
int me[Maxn][Maxm];
vector <int> cycles;
int res[Maxn][Maxm];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] %= Maxm;
        if (a[i] < 0) a[i] += Maxm;
    }
    for (int i = 1; i <= n; i++) {
        int k; scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int e; scanf("%d", &e);
            neigh[i].push_back(e);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < Maxm; j++) if (!res[i][j]) {
            seq.clear();
            ii v = ii(i, j);
            while (!res[v.first][v.second] && !me[v.first][v.second]) {
                seq.push_back(v); me[v.first][v.second] = seq.size();
                v.second = (v.second + a[v.first]) % Maxm;
                v.first = neigh[v.first][v.second % int(neigh[v.first].size())];
            }
            if (res[v.first][v.second]) {
                for (int i = 0; i < seq.size(); i++) {
                    ii u = seq[i];
                    res[u.first][u.second] = res[v.first][v.second];
                }
                continue;
            }
            set <int> tmp;
            for (int i = me[v.first][v.second] - 1; i < seq.size(); i++) {
                ii u = seq[i];
                tmp.insert(u.first);
            }
            cycles.push_back(int(tmp.size()));
            for (int i = 0; i < seq.size(); i++) {
                ii u = seq[i];
                res[u.first][u.second] = cycles.size();
            }
        }
    int q; scanf("%d", &q);
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        y %= Maxm;
        if (y < 0) y += Maxm;
        printf("%d\n", cycles[res[x][y] - 1]);
    }
    return 0;
}