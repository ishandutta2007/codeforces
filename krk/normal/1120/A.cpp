#include <bits/stdc++.h>
using namespace std;

const int Maxm = 500005;

int m, k, n, s;
int a[Maxm];
int lft[Maxm], tot;
bool mark[Maxm];
vector <int> res;

void Add(int x)
{
    if (lft[x] == 1) tot--;
    lft[x]--;
}

void Rem(int x)
{
    if (lft[x] == 0) tot++;
    lft[x]++;
}

int main()
{
    scanf("%d %d %d %d", &m, &k, &n, &s);
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= s; i++) {
        int b; scanf("%d", &b);
        lft[b]++;
    }
    for (int i = 0; i < Maxm; i++)
        if (lft[i] > 0) tot++;
    int r = 0;
    for (int i = 1; i + k - 1 <= m; i++) {
        while (r <= m && (tot > 0 || r - i < k)) { Add(a[r]); r++; }
        int rem = (i - 1) % k + r - i - k;
        if (tot == 0 && rem <= m - k * n) {
            int rem = r - i - k;
            for (int j = i; j < r; j++)
                if (lft[a[j]] < 0 && rem > 0) {
                    lft[a[j]]++;
                    rem--;
                } else mark[j] = true;
            int nd = n - 1;
            for (int j = 1; j + k <= i && nd > 0; j += k) {
                nd--;
                for (int z = j; z < j + k; z++)
                    mark[z] = true;
            }
            for (int j = m; j - k >= r - 1 && nd > 0; j -= k) {
                nd--;
                for (int z = j; z > j - k; z--)
                    mark[z] = true;
            }
            for (int j = 1; j <= m; j++) if (!mark[j])
                res.push_back(j);
            printf("%d\n", int(res.size()));
            for (int j = 0; j < res.size(); j++)
                printf("%d%c", res[j], j + 1 < res.size()? ' ': '\n');
            return 0;
        }
        Rem(a[i]);
    }
    printf("-1\n");
    return 0;
}