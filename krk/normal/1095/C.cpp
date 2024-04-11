#include <bits/stdc++.h>
using namespace std;

const int Maxn = 31;

int n, k;
int my[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < Maxn; i++)
        if (n & 1 << i) { my[i]++; k--; }
    if (k < 0) {
        printf("NO\n"); return 0;
    }
    for (int i = Maxn - 1; i > 0; i--) {
        int tk = min(k, my[i]);
        my[i - 1] += 2 * tk;
        my[i] -= tk; k -= tk;
    }
    if (k > 0) {
        printf("NO\n"); return 0;
    }
    printf("YES\n");
    bool pr = false;
    for (int i = 0; i < Maxn; i++)
        while (my[i]--) {
            if (pr) printf(" ");
            else pr = true;
            printf("%d", (1 << i));
        }
    printf("\n");
    return 0;
}