#include <bits/stdc++.h>
using namespace std;

int A, B;
int res;

int main()
{
    scanf("%d %d", &A, &B);
    int n = A + B;
    for (int i = 1; i <= n; ) {
        int d = n / i;
        int j = n / d;
        int md = n % j;
        int got = A % d + B % d;
        int all = j - i + 1;
        if (B % d <= B / d && A % d <= A / d && got % d == md) {
            int hm = (got - md) / d;
            int give0 = (B / d - B % d) / (d + 1);
            int give1 = (A / d - A % d) / (d + 1);
            int give = give0 + give1;
            if (hm < all) res += min(all - hm, give + 1);
        }
        i = j + 1;
    }
    printf("%d\n", res);
    return 0;
}