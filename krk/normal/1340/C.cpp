#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const ll bInf = 4000000000000000000ll;
const int Inf = 1000000000;
const int Maxn = 10005;
const int Maxm = 1005;

int n, m;
int seq[Maxn];
int g, r;
ii Q[2 * Maxn * Maxm];
int st = Maxn * Maxm, en = Maxn * Maxm;
int dist[Maxn][Maxm];
ll res = bInf;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &seq[i]);
    sort(seq, seq + m);
    scanf("%d %d", &g, &r);
    fill((int*)dist, (int*)dist + Maxn * Maxm, Inf);
    dist[0][g] = 0;
    Q[en++] = ii(0, g);
    while (st < en) {
        ii v = Q[st++];
        int d = dist[v.first][v.second];
        if (n - seq[v.first] <= v.second)
            res = min(res, ll(g + r) * d + ll(g - (v.second - n + seq[v.first])));
        if (v.second == 0 && d + 1 < dist[v.first][g]) {
            dist[v.first][g] = d + 1;
            Q[en++] = ii(v.first, g);
        }
        if (v.first > 0) {
            int add = seq[v.first] - seq[v.first - 1];
            if (add <= v.second && d < dist[v.first - 1][v.second - add]) {
                dist[v.first - 1][v.second - add] = d;
                Q[--st] = ii(v.first - 1, v.second - add);
            }
        }
        if (v.first + 1 < m) {
            int add = seq[v.first + 1] - seq[v.first];
            if (add <= v.second && d < dist[v.first + 1][v.second - add]) {
                dist[v.first + 1][v.second - add] = d;
                Q[--st] = ii(v.first + 1, v.second - add);
            }
        }
    }
    if (res >= bInf) cout << "-1\n";
    else cout << res << endl;
    return 0;
}