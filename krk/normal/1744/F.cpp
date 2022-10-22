#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int inp[Maxn];

ll Add(int a, int b) { return ll(a + b) * (a - b + 1) / 2ll; }

ll Solve(int x, int y, int allow)
{
    if (allow < 0) return 0;
    x = min(x, allow);
    y = min(y, allow);
    int hm = allow - y;
    if (x <= hm) return ll(x + 1) * (y + 1);
    ll res = ll(hm) * (y + 1);
    int tk = min(x - hm, y) + 1;
    res += Add(y + 1, y + 2 - tk);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int p; scanf("%d", &p);
            inp[p] = i;
        }
        int lef = inp[0], rig = inp[0], al = 1;
        ll res = 0ll;
        for (int i = 1; i < n; i++)
            if (inp[i] < lef) {
                res += Solve(lef - inp[i] - 1, n - rig, al);
                al += 1 - (lef - inp[i] - 1);
                lef = inp[i];
            } else if (rig < inp[i]) {
                res += Solve(lef - 1, inp[i] - rig - 1, al);
                al += 1 - (inp[i] - rig - 1);
                rig = inp[i];
            } else al += 2;
        res += Solve(lef - 1, n - rig, al);
        printf("%I64d\n", res);
    }
    return 0;
}