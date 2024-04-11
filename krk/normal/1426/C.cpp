#include <bits/stdc++.h>
using namespace std;

const int lim = 64000;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int res = lim;
        for (int i = 1; i <= lim; i++)
            if (n <= i) res = min(res, i - 1);
            else res = min(res, i - 1 + (n - i) / i + int((n - i) % i > 0));
        printf("%d\n", res);
    }
    return 0;
}