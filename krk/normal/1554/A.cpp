#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100004;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int a; scanf("%d", &a);
        ll res = 0;
        for (int i = 2; i <= n; i++) {
            int cur; scanf("%d", &cur);
            res = max(res, ll(cur) * a);
            a = cur;
        }
        printf("%I64d\n", res);
    }
    return 0;
}