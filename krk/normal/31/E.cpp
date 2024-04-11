#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 19;

int n;
char s[40];
ll pw[Maxn];
ll best[Maxn][Maxn];
char p[Maxn][Maxn];

void Calc(int a, int b)
{
    if (best[a][b] == -1LL) {
        if (a < n) {
            Calc(a + 1, b);
            best[a][b] = (s[a + b] - '0') * pw[n - 1 - a] + best[a + 1][b];
            p[a][b] = 'H';
        }
        if (b < n) {
            Calc(a, b + 1);
            ll cand = (s[a + b] - '0') * pw[n - 1 - b] + best[a][b + 1];
            if (cand > best[a][b]) {
                best[a][b] = cand; p[a][b] = 'M';
            }
        }
        best[a][b] = max(0LL, best[a][b]);
    }
}

int main()
{
    pw[0] = 1LL;
    for (int i = 1; i < Maxn; i++) pw[i] = 10LL * pw[i - 1];
    scanf("%d %s", &n, s);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) best[i][j] = -1LL;
    Calc(0, 0);
    int a = 0, b = 0;
    while (a < n || b < n) {
        printf("%c", p[a][b]);
        if (p[a][b] == 'H') a++;
        else b++;
    }
    printf("\n");
    return 0;
}