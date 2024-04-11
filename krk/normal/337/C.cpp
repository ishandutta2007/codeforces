#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000009;

int n, m, k;
int res;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    int cg = n / k * (k - 1) + n % k;
    if (cg >= m) { printf("%d\n", m); return 0; }
    res = m;
    m -= cg;
    int pw = 1;
    int a = 2, p = m;
    while (p) {
        if (p & 1) pw = ll(pw) * ll(a) % ll(mod);
        p >>= 1; a = ll(a) * ll(a) % ll(mod);
    }
    pw = (pw - 1 + mod) % mod;
    pw = 2 * pw % mod;
    pw = (pw - m + mod) % mod;
    pw = ll(pw) * ll(k) % ll(mod);
    res = (res + pw) % mod;
    printf("%d\n", res);
    return 0;
}