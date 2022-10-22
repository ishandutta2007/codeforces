#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1000005;

int inv[Maxn];
int a, b, n;
int res;

void gcd(int a, int &x, int b, int &y)
{
    if (a == 0) { x = 0; y = 1; }
    else {
        int xx, yy; gcd(b % a, xx, a, yy);
        x = yy - b / a * xx, y = xx;
    }
}

int Inv(int a)
{
    int x, y; gcd(a, x, mod, y);
    if (x < 0) x += mod;
    return x;
}

bool goodRes(int x)
{
    while (x) {
        if (x % 10 != a && x % 10 != b) return false;
        x /= 10;
    }
    return true;
}

int main()
{
    for (int i = 1; i < Maxn; i++) inv[i] = Inv(i);
    scanf("%d %d %d", &a, &b, &n);
    int C = 1;
    for (int i = 0; i <= n; i++) {
        if (goodRes(i * a + (n - i) * b)) res = (res + C) % mod;
        C = ll(C) * ll(n - i) % ll(mod) * ll(inv[i + 1]) % ll(mod);
    }
    printf("%d\n", res);
    return 0;
}