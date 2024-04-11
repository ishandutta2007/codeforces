#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 22;

int n, a[Maxn];
int num[1 << Maxm][2], len[1 << Maxm];

int Get(int i)
{
    int mask = ~a[i] & (1 << Maxm) - 1;
    for (int j = 0; j < len[mask]; j++)
        if (num[mask][j] != i) return a[num[mask][j]];
    return -1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (len[a[i]] < 2) num[a[i]][len[a[i]]++] = i;
    }
    for (int i = 0; i < (1 << Maxm) - 1; i++)
        for (int j = 0; j < Maxm; j++) if (!(i & 1 << j)) {
            int k = i | 1 << j;
            for (int l = 0; l < len[i] && len[k] < 2; l++)
                if (len[k] == 0 || len[k] == 1 && num[k][0] != num[i][l])
                    num[k][len[k]++] = num[i][l];
        }
    for (int i = 0; i < n; i++) printf("%d%c", Get(i), i + 1 < n? ' ': '\n');
    return 0;
}