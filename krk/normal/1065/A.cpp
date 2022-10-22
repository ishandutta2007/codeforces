#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int s, a, b, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &s, &a, &b, &c);
        ll tk = s / c;
        ll res = tk + tk / a * b;
        printf("%I64d\n", res);
    }
    return 0;
}