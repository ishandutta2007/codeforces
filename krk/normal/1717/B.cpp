#include <bits/stdc++.h>
using namespace std;

int T;
int n, k, r, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &k, &r, &c);
        int nd = (r + c) % k;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                printf("%c", (i + j) % k == nd? 'X': '.');
            printf("\n");
        }
    }
    return 0;
}