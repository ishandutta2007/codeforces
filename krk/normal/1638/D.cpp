#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 1005;

int n, m;
int B[Maxn][Maxn];
bool tk[Maxn][Maxn];
vector <iii> seq;

int Check(int r, int c)
{
    if (r <= 0 || r >= n || c <= 0 || c >= m || tk[r][c]) return -1;
    int lst = -1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) if (B[r + i][c + j])
            if (lst == -1) lst = B[r + i][c + j];
            else if (lst != B[r + i][c + j]) return -1;
    return lst == -1? 1: lst;
}

void Mark(int r, int c)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            B[r + i][c + j] = 0;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &B[i][j]);
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            int g = Check(i, j);
            if (g != -1) {
                tk[i][j] = true;
                Mark(i, j);
                seq.push_back(iii(ii(i, j), g));
            }
        }
    for (int z = 0; z < seq.size(); z++) {
        auto v = seq[z].first;
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++) {
                ii u = ii(v.first + i, v.second + j);
                int g = Check(u.first, u.second);
                if (g != -1) {
                    tk[u.first][u.second] = true;
                    Mark(u.first, u.second);
                    seq.push_back(iii(u, g));
                }
            }
    }
    if (seq.size() == (n - 1) * (m - 1)) {
        printf("%d\n", int(seq.size()));
        for (int i = int(seq.size()) - 1; i >= 0; i--)
            printf("%d %d %d\n", seq[i].first.first, seq[i].first.second, seq[i].second, i - 1 >= 0? ' ': '\n');
    } else printf("-1\n");
    return 0;
}