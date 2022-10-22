#include <bits/stdc++.h>
using namespace std;

int t;
int a, b, c;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &c);
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a + b <= c) printf("%d\n", a + b);
        else printf("%d\n", (a + b + c) / 2);
    }
    return 0;
}