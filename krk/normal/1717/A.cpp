#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int res = n;
        res += n / 2 * 2 + n / 3 * 2;
        printf("%d\n", res);
    }
    return 0;
}