#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n, m;
char B[Maxn][Maxn];
int tak;
bool vis[Maxn][Maxn];
vector <int> y, x;

bool Check(int x1, int y1, int x2, int y2)
{
    if (x2 - x1 < 2 || y2 - y1 < 2) return false;
    for (int i = x1; i <= x2; i++) if (B[i][y1] == '.' || B[i][y2] == '.') return false;
    for (int j = y1; j <= y2; j++) if (B[x1][j] == '.' || B[x2][j] == '.') return false;
    return true;
}

int Count(int x1, int y1, int x2, int y2)
{
    int res = 0;
    for (int i = x1; i <= x2; i++) {
        if (!vis[i][y1]) { res++; vis[i][y1] = true; }
        if (!vis[i][y2]) { res++; vis[i][y2] = true; }
    }
    for (int j = y1; j <= y2; j++) {
        if (!vis[x1][j]) { res++; vis[x1][j] = true; }
        if (!vis[x2][j]) { res++; vis[x2][j] = true; }
    }
    return res;
}

void Clear(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i <= x2; i++) vis[i][y1] = vis[i][y2] = false;
    for (int j = y1; j <= y2; j++) vis[x1][j] = vis[x2][j] = false;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf(" %c", &B[i][j]);
            tak += B[i][j] == '#';
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j + 2 < m; j++)
            if (B[i][j] == '#' && B[i][j + 1] == '#' && B[i][j + 2] == '#') {
                y.push_back(i); break;
            }
    for (int j = 0; j < m; j++)
        for (int i = 0; i + 2 < n; i++)
            if (B[i][j] == '#' && B[i + 1][j] == '#' && B[i + 2][j] == '#') {
                x.push_back(j); break;
            }
    if (y.size() > 4 && x.size() > 4) { printf("NO\n"); return 0; }
    if (y.size() > 4) {
        vector <int> tmp;
        tmp.push_back(y[0]); tmp.push_back(y[1]); tmp.push_back(y[y.size() - 2]); tmp.push_back(y.back());
        y = tmp;
    }
    if (x.size() > 4) {
        vector <int> tmp;
        tmp.push_back(x[0]); tmp.push_back(x[1]); tmp.push_back(x[x.size() - 2]); tmp.push_back(x.back());
        x = tmp;
    }
    bool found = false;
    for (int i1 = 0; i1 < y.size() && !found; i1++)
        for (int i2 = i1 + 1; i2 < y.size() && !found; i2++)
            for (int j1 = 0; j1 < x.size() && !found; j1++)
                for (int j2 = j1 + 1; j2 < x.size() && !found; j2++) if (Check(y[i1], x[j1], y[i2], x[j2]))
                    for (int i3 = 0; i3 < y.size() && !found; i3++)
                        for (int i4 = i3 + 1; i4 < y.size() && !found; i4++)
                            for (int j3 = 0; j3 < x.size() && !found; j3++)
                                for (int j4 = j3 + 1; j4 < x.size() && !found; j4++)
                                    if (Check(y[i3], x[j3], y[i4], x[j4]))
                                        if (Count(y[i1], x[j1], y[i2], x[j2]) +
                                            Count(y[i3], x[j3], y[i4], x[j4]) == tak) {
                                            found = true;
                                            printf("YES\n");
                                            printf("%d %d %d %d\n", y[i1] + 1, x[j1] + 1, y[i2] + 1, x[j2] + 1);
                                            printf("%d %d %d %d\n", y[i3] + 1, x[j3] + 1, y[i4] + 1, x[j4] + 1);
                                    } else {
                                        Clear(y[i1], x[j1], y[i2], x[j2]);
                                        Clear(y[i3], x[j3], y[i4], x[j4]);
                                    }
    if (!found) printf("NO\n");
    return 0;
}