#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 2002;

char C[maxn][maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    queue<pii> q;

    for (int i = 1; i <= n; ++i){
        scanf("%s", C[i] + 1);
        for (int j = 1; j <= m; ++j)
            if (C[i][j] == '.') q.push({i, j});
    }

    while (!q.empty()){
        pii p = q.front(); q.pop();
        int x = p.first, y = p.second;

        for (int i = x - 1; i <= x; ++i)
            for (int j = y - 1; j <= y; ++j){
                if (min(i, j) == 0 || i == n || j == m) continue;

                int tot = 0, bx, by;
                for (int dx = 0; dx < 2 && tot < 2; ++dx)
                    for (int dy = 0; dy < 2 && tot < 2; ++dy){
                        if (C[i + dx][j + dy] == '*'){
                            tot++; bx = i + dx, by = j + dy;
                        }
                }

                if (tot == 1){
                    C[bx][by] = '.';
                    q.push({bx, by});
                }
            }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            putchar(C[i][j]);
        putchar('\n');
    }

    return 0;
}