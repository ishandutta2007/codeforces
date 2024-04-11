#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 30;

ll pw3[Maxb + 1];
int t;
int l, r;
ll res;

void Gen(int b, int val1, int val2)
{
    if (val1 > r || val1 + (1 << b + 1) - 1 < l ||
        val2 > r || val2 + (1 << b + 1) - 1 < l)
        return;
    if (l <= val1 && val1 + (1 << b + 1) - 1 <= r &&
        l <= val2 && val2 + (1 << b + 1) - 1 <= r) {
        res += pw3[b + 1];
        return;
    }
    Gen(b - 1, val1 | 1 << b, val2);
    Gen(b - 1, val1, val2 | 1 << b);
    Gen(b - 1, val1, val2);
}

int main()
{
    pw3[0] = 1;
    for (int i = 1; i <= Maxb; i++)
        pw3[i] = pw3[i - 1] * 3ll;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &l, &r);
        res = 0;
        Gen(Maxb - 1, 0, 0);
        printf("%I64d\n", res);
    }
    return 0;
}