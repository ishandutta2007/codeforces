#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int T;
int n, m;
char B[Maxn][Maxn];
vector <ii> V;

bool Check(const vector <ii> &V)
{
    int x1 = Maxn, x2 = -Maxn, y1 = Maxn, y2 = -Maxn;
    for (int i = 0; i < V.size(); i++) {
        x1 = min(x1, V[i].first);
        x2 = max(x2, V[i].first);
        y1 = min(y1, V[i].second);
        y2 = max(y2, V[i].second);
    }
    return V.size() == (x2 - x1 + 1) * (y2 - y1 + 1);
}

void Fill(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= m || B[r][c] == '0') return;
    V.push_back(ii(r, c));
    B[r][c] = '0';
    for (int i = 0; i < Maxd; i++)
        Fill(r + dy[i], c + dx[i]);
}

bool Solve()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (B[i][j] == '1') {
            V.clear();
            Fill(i, j);
            if (!Check(V)) return false;
        }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", B[i]);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}