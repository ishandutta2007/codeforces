#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll k, b, n, t;
ll cur, d;

int main()
{
    scanf("%I64d %I64d %I64d %I64d", &k, &b, &n, &t);
    cur = 1LL;
    while (cur <= t) { cur = k * cur + b; d++; }
    d--;
    printf("%I64d\n", max(0LL, n - d));
    return 0;
}