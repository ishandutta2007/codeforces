#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, B, x, y;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &B, &x, &y);
        int cur = 0;
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            if (cur + x <= B) cur += x;
            else cur -= y;
            res += cur;
        }
        printf("%I64d\n", res);
    }
    return 0;
}