#include <bits/stdc++.h>
using namespace std;

int t;
int a, b, c;
int bc, cc;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &c);
        scanf("%d %d", &bc, &cc);
        int tk = min(a / 2, b);
        int res1 = tk * bc + min((a - 2 * tk) / 2, c) * cc;
        tk = min(a / 2, c);
        int res2 = tk * cc + min((a - 2 * tk) / 2, b) * bc;
        printf("%d\n", max(res1, res2));
    }
    return 0;
}