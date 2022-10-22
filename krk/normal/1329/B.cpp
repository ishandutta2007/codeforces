#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 30;

int T;
int d, m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &d, &m);
        int res = 1 % m;
        for (int i = 0; i < Maxb; i++) if ((1 << i) <= d) {
            int mn = min(d - (1 << i) + 1, (1 << i));
            res = ll(res) * (mn + 1) % m;
        }
        res = (res - 1 % m + m) % m;
        printf("%d\n", res);
    }
    return 0;
}