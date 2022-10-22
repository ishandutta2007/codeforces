#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    int mx = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        if (a == mx) mx++;
        else if (a > mx) { printf("%d\n", i); return 0; }
    }
    printf("-1\n");
    return 0;
}