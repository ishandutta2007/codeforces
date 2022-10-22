#include <bits/stdc++.h>
using namespace std;

int t;
int n, x, a, b;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &n, &x, &a, &b);
        if (a > b) swap(a, b);
        int rem = a - 1 + n - b;
        int res = b - a + min(rem, x);
        printf("%d\n", res);
    }
    return 0;
}