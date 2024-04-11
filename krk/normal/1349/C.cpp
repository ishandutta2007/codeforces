#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Inf = 1000000000;
const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m, t;
char B[Maxn][Maxn];
bool mark[Maxn][Maxn];
vector <ii> seq;
int dist[Maxn][Maxn];

void Mark(int r, int c, char val)
{
    if (r < 0 || r >= n || c < 0 || c >= m || mark[r][c] || val != B[r][c]) return;
    mark[r][c] = true;
    seq.push_back(ii(r, c));
    for (int i = 0; i < Maxd; i++)
        Mark(r + dy[i], c + dx[i], val);
}

int main()
{
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    fill((int*)dist, (int*)dist + Maxn * Maxn, Inf);
    vector <ii> Q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (!mark[i][j]) {
            seq.clear();
            Mark(i, j, B[i][j]);
            if (seq.size() > 1)
                for (int k = 0; k < seq.size(); k++) {
                    ii v = seq[k];
                    dist[v.first][v.second] = 0;
                    Q.push_back(v);
                }
        }
    for (int i = 0; i < Q.size(); i++) {
        ii v = Q[i];
        int dis = dist[v.first][v.second];
        for (int d = 0; d < Maxd; d++) {
            ii u = ii(v.first + dy[d], v.second + dx[d]);
            if (0 <= u.first && u.first < n && 0 <= u.second && u.second < m &&
                dis + 1 < dist[u.first][u.second]) {
                dist[u.first][u.second] = dis + 1;
                Q.push_back(u);
            }
        }
    }
    while (t--) {
        int i, j; ll p; scanf("%d %d %I64d", &i, &j, &p); i--; j--;
        if (dist[i][j] >= Inf || dist[i][j] > p) printf("%c", B[i][j]);
        else if (dist[i][j] % 2 == p % 2) printf("%c", B[i][j]);
             else printf("%c", ('1' - B[i][j] + '0'));
        printf("\n");
    }
    return 0;
}