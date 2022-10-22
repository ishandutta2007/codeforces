#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int tmp; scanf("%d", &tmp);
        }
        n = 10 - n;
        printf("%d\n", n * (n - 1) * 3);
    }
    return 0;
}