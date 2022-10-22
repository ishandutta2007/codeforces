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
        ll pw = 1;
        ll add = 0;
        ll num = n;
        while (num) {
            if (num % 3 > 1) {
                num++; add = pw;
            }
            num /= 3; pw *= 3ll;
        }
        add *= 3;
        if (add == 0) printf("%I64d\n", n);
        else printf("%I64d\n", (n + add) / add * add);
    }
    return 0;
}