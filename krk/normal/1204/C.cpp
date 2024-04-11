#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
const int Inf = 1000000000;
const int Maxm = 1000005;

int n;
int dist[Maxn][Maxn];
int m;
int p[Maxm];
vector <int> res;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            char ch; scanf(" %c", &ch);
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = ch == '1'? 1: Inf;
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &p[i]);
    res.push_back(1);
    for (int j = 2; j <= m; j++)
        if (dist[p[res.back()]][p[j]] != j - res.back())
            res.push_back(j - 1);
    res.push_back(m);
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", p[res[i]], i + 1 < res.size()? ' ': '\n');
    return 0;
}