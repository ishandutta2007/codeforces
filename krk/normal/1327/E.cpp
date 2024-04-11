#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;

int n;
int pw[Maxn];

int main()
{
    pw[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw[i] = 10ll * ll(pw[i - 1]) % mod;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int res = 0;
        if (i < n) {
            res = 20ll * 9ll * ll(pw[n - i - 1]) % mod;
            if (i < n - 1) res = (res + 10ll * 9ll * 9ll * ll(n - i - 1) % mod * ll(pw[n - i - 2])) % mod;
        } else res = 10;
        printf("%d%c", res, i + 1 <= n? ' ': '\n');
    }
    return 0;
}