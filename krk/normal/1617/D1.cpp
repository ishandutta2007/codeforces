#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int T;
int n;
bool res[Maxn];

int Ask(int a, int b, int c)
{
    printf("? %d %d %d\n", a, b, c); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(res, res + n + 1, false);
        int good, bad;
        int cur = Ask(1, 2, 3);
        for (int i = 3; i + 1 <= n; i++) {
            int got = Ask(i - 1, i, i + 1);
            if (got != cur) {
                good = i - 2;
                bad = i + 1;
                if (got == 1) swap(good, bad);
                break;
            }
        }
        res[bad] = true;
        for (int i = 1; i <= n; i++) if (i != good && i != bad)
            if (!Ask(good, bad, i)) res[i] = true;
        vector <int> ans;
        for (int i = 1; i <= n; i++) if (res[i])
            ans.push_back(i);
        printf("! %d", int(ans.size()));
        for (int i = 0; i < ans.size(); i++)
            printf(" %d", ans[i]);
        printf("\n"); fflush(stdout);
    }
    return 0;
}