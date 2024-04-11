#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        int res = n <= k? k - n: int(n % 2 != k % 2);
        printf("%d\n", res);
    }
    return 0;
}