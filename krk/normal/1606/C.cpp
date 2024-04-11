#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxd = 10;

ll pw[Maxd];
int T;
int n, k;
int has;

int main()
{
    pw[0] = 1;
    for (int i = 1; i < Maxd; i++)
        pw[i] = 10ll * pw[i - 1];
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        k++;
        has = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            has |= 1 << a;
        }
        ll res = 0;
        int lst = 0;
        for (int i = 1; i < Maxd; i++) if (has & 1 << i) {
            ll lft = min(pw[i] / pw[lst] - 1, ll(k));
            res += lft * pw[lst];
            k -= lft;
            lst = i;
        }
        res += k * pw[lst];
        printf("%I64d\n", res);
    }
    return 0;
}