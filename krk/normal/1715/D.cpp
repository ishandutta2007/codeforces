#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxb = 30;

int n, q;
vector <int> neigh[Maxn][Maxb];
bool tk[Maxn][Maxb];
int val[Maxn][Maxb];
queue <ii> Q;

void set0(int a, int b)
{
    if (tk[a][b]) return;
    tk[a][b] = true;
    Q.push(ii(a, b));
}

void set1(int a, int b)
{
    tk[a][b] = true;
    val[a][b] = 1;
}

int main()
{
    scanf("%d %d", &n, &q);
    while (q--) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        if (a == b)
            for (int i = 0; i < Maxb; i++)
                if (c & 1 << i) set1(a, i);
                else set0(a, i);
        else for (int i = 0; i < Maxb; i++)
                if (c & 1 << i) {
                    neigh[a][i].push_back(b);
                    neigh[b][i].push_back(a);
                } else {
                    set0(a, i);
                    set0(b, i);
                }
    }
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int b = Maxb - 1; b >= 0; b--) {
            while (!Q.empty()) {
                ii v = Q.front(); Q.pop();
                for (int z = 0; z < neigh[v.first][v.second].size(); z++) {
                    int u = neigh[v.first][v.second][z];
                    set1(u, v.second);
                }
            }
            if (val[i][b]) res |= 1 << b;
            if (tk[i][b]) continue;
            set0(i, b);
        }
        printf("%d%c", res, i + 1 <= n? ' ': '\n');
    }
    return 0;
}