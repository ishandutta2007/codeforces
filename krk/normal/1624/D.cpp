#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;
const int Maxn = 200005;

int T;
int n, k;
char str[Maxn];
int cnt[Maxl];
int has[Maxn];

int Solve(int od, int tot)
{
    od = min(od, k);
    int hm = tot / k;
    int res = 2 * hm; tot %= k;
    if (tot < k - od) return res;
    return res + 1;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        fill(cnt, cnt + Maxl, 0);
        fill(has, has + Maxn, 0);
        scanf("%s", str);
        for (int i = 0; i < n; i++)
            cnt[str[i] - 'a']++;
        int pnt = 0, tot = 0, od = 0;
        for (int i = 0; i < Maxl; i++) {
            if (cnt[i] % 2) od++;
            tot += cnt[i] / 2;
        }
        int res = Solve(od, tot);
        while (tot > 0) {
            od += 2;
            tot--;
            res = max(res, Solve(od, tot));
        }
        printf("%d\n", res);
    }
    return 0;
}