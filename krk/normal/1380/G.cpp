#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int mod = 998244353;

int n;
int c[Maxn];
ll S[Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++)
        S[i] = S[i - 1] + c[i];
    int mult = Inv(n);
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = n, c = 0; j > 0; j -= i, c++) {
            ll cur = S[j];
            if (j - i > 0) cur -= S[j - i];
            cur = cur % mod * ll(c) % mod;
            res = (res + cur) % mod;
        }
        res = ll(res) * mult % mod;
        printf("%d%c", res, i + 1 <= n? ' ': '\n');
    }
    return 0;
}