#include <bits/stdc++.h>
using namespace std;

int t;
int r, g, b;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &r, &g, &b);
        if (r > g) swap(r, g);
        if (g > b) swap(g, b);
        if (r > g) swap(r, g);
        if (r + g >= b - 1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}