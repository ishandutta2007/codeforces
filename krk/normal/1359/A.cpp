#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        int tk = min(n / k, m);
        int oth = (m - tk) / (k - 1) + int(bool((m - tk) % (k - 1) > 0));
        printf("%d\n", tk - oth);
    }
    return 0;
}