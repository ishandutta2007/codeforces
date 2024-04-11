#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, m;
int B[Maxn][Maxn];
vector <int> rows[Maxn], cols[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
            rows[i].push_back(B[i][j]);
            cols[j].push_back(B[i][j]);
        }
    for (int i = 0; i < n; i++) {
        sort(rows[i].begin(), rows[i].end());
        rows[i].erase(unique(rows[i].begin(), rows[i].end()), rows[i].end());
    }
    for (int i = 0; i < m; i++) {
        sort(cols[i].begin(), cols[i].end());
        cols[i].erase(unique(cols[i].begin(), cols[i].end()), cols[i].end());
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x = B[i][j];
            int a1 = lower_bound(rows[i].begin(), rows[i].end(), x) - rows[i].begin();
            int a2 = lower_bound(cols[j].begin(), cols[j].end(), x) - cols[j].begin();
            int c1 = rows[i].end() - upper_bound(rows[i].begin(), rows[i].end(), x);
            int c2 = cols[j].end() - upper_bound(cols[j].begin(), cols[j].end(), x);
            printf("%d%c", max(c1, c2) + max(a1, a2) + 1, j + 1 < m? ' ': '\n');
        }
    return 0;
}