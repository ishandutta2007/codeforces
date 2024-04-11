#include <bits/stdc++.h>
using namespace std;

int q;
int a, b, c;

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d", &a, &b, &c);
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        if (c - a <= 2) printf("0\n");
        else printf("%d\n", 2 * (c - a - 2));
    }
    return 0;
}