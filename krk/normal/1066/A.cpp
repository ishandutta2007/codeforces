#include <bits/stdc++.h>
using namespace std;

int t;
int L, v, l, r;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &L, &v, &l, &r);
        printf("%d\n", L / v - r / v + (l - 1) / v);
    }
    return 0;
}