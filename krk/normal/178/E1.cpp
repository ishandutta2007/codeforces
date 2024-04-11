#include <cstdio>
using namespace std;

const int Maxn = 2005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n;
int pic[Maxn][Maxn];
int res1, res2;

void Fill(int r, int c)
{
    if (pic[r][c] == 0) return;
    pic[r][c] = 0;
    for (int i = 0; i < Maxd; i++) Fill(r + dy[i], c + dx[i]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &pic[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (pic[i][j] == 1) {
                if (pic[i - 1][j] == 0 && pic[i][j - 1] == 0 && pic[i - 1][j - 1] == 0) {
                    int l = 0;
                    while (pic[i + l][j - 1] == 0 && pic[i + l][j] == 1) l++;
                    if (l >= 15) res2++;
                    else res1++;
                } else res1++;
                Fill(i, j);
            }
    printf("%d %d\n", res1, res2);
    return 0;
}