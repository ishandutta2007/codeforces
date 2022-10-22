#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int q;
ll n;

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%I64d", &n);
        int res = 0;
        while (n % 2 == 0) { res++; n /= 2; }
        while (n % 3 == 0) { res += 2; n /= 3; }
        while (n % 5 == 0) { res += 3; n /= 5; }
        if (n == 1) printf("%d\n", res);
        else printf("-1\n");
    }
    return 0;
}