#include <bits/stdc++.h>
using namespace std;

int q;
int l, r, d;

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d", &l, &r, &d);
        if (d < l) printf("%d\n", d);
        else printf("%d\n", (r / d + 1) * d);
    }
    return 0;
}