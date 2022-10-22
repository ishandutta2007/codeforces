#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int q;
ll a[3];

int main()
{
    scanf("%d", &q);
    while (q--) {
        for (int i = 0; i < 3; i++)
            scanf("%I64d", &a[i]);
        printf("%I64d\n", (a[0] + a[1] + a[2]) / 2ll);
    }
    return 0;
}