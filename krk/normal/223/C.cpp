#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int mod = 1000000007;

int n, k;
int a[Maxn];
int d[Maxn];

void Euclid(int a, int b, int &x, int &y)
{
    if (!b) { x = 1; y = 0; }
    else {
        int xx, yy;
        Euclid(b, a % b, xx, yy);
        x = yy;
        y = xx - a / b * yy;
    }
}

int Inv(int a)
{
    int x, y;
    Euclid(a, mod, x, y);
    if (x < 0) x += mod;
    return x;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    d[0] = 1;
    for (int i = 1; i < n; i++) d[i] = ll(k + i - 1) * ll(Inv(i)) % ll(mod) * d[i - 1] % ll(mod);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) sum = (sum + ll(a[j]) * ll(d[i - j]) % ll(mod)) % ll(mod);
        printf("%d%c", sum, i + 1 < n? ' ': '\n');
    }
    return 0;
}