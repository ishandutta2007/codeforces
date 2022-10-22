#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int a, b, c, d;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a <= b) printf("%d\n", b);
        else if (d >= c) printf("-1\n");
        else {
            int lft = a - b;
            int nd = (lft - 1) / (c - d) + 1;
            ll res = b + ll(nd) * c;
            printf("%I64d\n", res);
        }
    }
    return 0;
}