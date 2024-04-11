#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;

int a, b;

int main()
{
    scanf("%d %d", &a, &b);
    int res = 1;
    for (int i = 0; i < a + b; i++)
        res = 2ll * ll(res) % mod;
    printf("%d\n", res);
    return 0;
}