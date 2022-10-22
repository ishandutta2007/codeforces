#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l, r;

int main()
{
    scanf("%I64d %I64d", &l, &r);
    printf("YES\n");
    while (l < r) {
        printf("%I64d %I64d\n", l, l + 1);
        l += 2;
    }
    return 0;
}