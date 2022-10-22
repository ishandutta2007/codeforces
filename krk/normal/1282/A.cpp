#include <bits/stdc++.h>
using namespace std;

int t;
int a, b, c, r;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &a, &b, &c, &r);
        if (a > b) swap(a, b);
        int mn = max(a, c - r), mx = min(b, c + r);
        if (mn <= mx)
            printf("%d\n", mn - a + b - mx);
        else printf("%d\n", b - a);
    }
    return 0;
}