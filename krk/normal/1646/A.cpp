#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n, s;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d", &n, &s);
        printf("%I64d\n", s / (n * n));
    }
    return 0;
}