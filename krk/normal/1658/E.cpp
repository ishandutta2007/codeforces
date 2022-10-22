#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;

int n, k;
int B[Maxn][Maxn];
ii pos[Maxn * Maxn];
bool win[Maxn * Maxn];
char res[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
            pos[B[i][j]] = ii(i + j, i - j);
        }
    int r1 = 0, r2 = 2 * n - 2;
    int c1 = -(n - 1), c2 = n - 1;
    for (int i = n * n; i > 0; i--) {
        auto p = pos[i];
        if (r1 <= p.first && p.first <= r2 && c1 <= p.second && p.second <= c2) {
            win[i] = true;
            r1 = max(r1, p.first - k);
            r2 = min(r2, p.first + k);
            c1 = max(c1, p.second - k);
            c2 = min(c2, p.second + k);
        }
    }
    res[n] = '\0';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (win[B[i][j]]) res[j] = 'M';
            else res[j] = 'G';
        printf("%s\n", res);
    }
    return 0;
}