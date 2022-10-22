#include <bits/stdc++.h>
using namespace std;

int n;
int mn = 1000000007;
int mx = -1000000007;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        mn = min(mn, a);
        mx = max(mx, a);
    }
    printf("%d\n", mx - mn + 1 - n);
    return 0;
}