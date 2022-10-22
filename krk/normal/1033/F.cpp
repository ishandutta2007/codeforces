#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 531441;
const int Maxb = 12;

int w, n, m;
int pw3[Maxb + 1];
int cnt[Maxm];
char tmp[Maxb + 5];
ll res;

void Gen(int lvl, int mask1, int mask2, int mult)
{
    if (lvl >= w) res += ll(mult) * cnt[mask1] * cnt[mask2];
    else if (tmp[lvl] == 'A') {
        Gen(lvl + 1, mask1 + 2 * pw3[lvl], mask2 + 2 * pw3[lvl], mult);
        Gen(lvl + 1, mask1 + pw3[lvl], mask2 + pw3[lvl], -mult);
    } else if (tmp[lvl] == 'O')
        Gen(lvl + 1, mask1, mask2, mult);
    else if (tmp[lvl] == 'X') {
        Gen(lvl + 1, mask1, mask2, mult);
        Gen(lvl + 1, mask1 + pw3[lvl], mask2 + pw3[lvl], mult);
    } else if (tmp[lvl] == 'a')
        Gen(lvl + 1, mask1 + pw3[lvl], mask2 + pw3[lvl], mult);
    else if (tmp[lvl] == 'o') {
        Gen(lvl + 1, mask1 + 2 * pw3[lvl], mask2 + 2 * pw3[lvl], mult);
        Gen(lvl + 1, mask1, mask2, -mult);
    } else {
        Gen(lvl + 1, mask1, mask2 + pw3[lvl], mult);
        Gen(lvl + 1, mask1 + pw3[lvl], mask2, mult);
    }
}

int main()
{
    pw3[0] = 1;
    for (int i = 1; i <= Maxb; i++)
        pw3[i] = 3 * pw3[i - 1];
    scanf("%d %d %d", &w, &n, &m);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        int mask = 0;
        for (int j = 0; j < w; j++)
            if (a & 1 << j)
                mask += pw3[w - 1 - j];
        cnt[mask]++;
    }
    for (int i = 0; i < w; i++)
        for (int j = 0; j < pw3[w]; j++)
            if (j / pw3[i] % 3 == 0)
                cnt[j + 2 * pw3[i]] += cnt[j];
            else if (j / pw3[i] % 3 == 1)
                cnt[j + pw3[i]] += cnt[j];
    while (m--) {
        scanf("%s", tmp);
        res = 0;
        Gen(0, 0, 0, 1);
        printf("%I64d\n", res);
    }
    return 0;
}