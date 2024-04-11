#include <cstdio>
#include <algorithm>
#pragma comment(linker, "/STACK:64777216")
using namespace std;

const int Maxn = 1005;
const int Maxd = 8;
const int dy[Maxd] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dx[Maxd] = {-1, 1, -2, 2, -2, 2, -1, 1};

int n, m;
int taken[Maxn][Maxn];
int res;

void Search(int r, int c, int col, int &w, int &b)
{
     if (r < 0 || r >= n || c < 0 || c >= m) return;
     if (taken[r][c]) return;
     taken[r][c] = col; w++;
     for (int i = 0; i < Maxd; i++) Search(r + dy[i], c + dx[i], -col, b, w);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int w = 0, b = 0;
            Search(i, j, 1, w, b);
            res += max(w, b);
        }
    printf("%d\n", res);
    return 0;
}