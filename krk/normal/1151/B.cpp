#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int n, m;
int B[Maxn][Maxn];
vector <int> seq[Maxn];
int my[Maxn];
int res;

int main()
{
    scanf("%d %d", &n, &m);
    int lst = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
            if (seq[i].empty() || B[i][seq[i].back()] != B[i][j])
                seq[i].push_back(j);
        }
        if (seq[i].size() > 1) lst = i;
        my[i] = 0; res ^= B[i][0];
    }
    if (res == 0)
        if (lst == -1) { printf("NIE\n"); return 0; }
        else { res ^= (B[lst][0] ^ B[lst][seq[lst][1]]); my[lst] = seq[lst][1]; }
    printf("TAK\n");
    for (int i = 0; i < n; i++)
        printf("%d%c", my[i] + 1, i + 1 < n? ' ': '\n');
    return 0;
}