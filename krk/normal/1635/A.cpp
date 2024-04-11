#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            res |= a;
        }
        printf("%d\n", res);
    }
    return 0;
}