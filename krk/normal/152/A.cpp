#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, m;
char mar[Maxn][Maxn];
char b[Maxn];
int res;

int main()
{
    fill(b, b + Maxn, '0');
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf(" %c", &mar[i][j]);
            b[j] = max(b[j], mar[i][j]);
        }
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < m && mar[i][j] < b[j]) j++;
        res += j < m;
    }
    printf("%d\n", res);
    return 0;
}