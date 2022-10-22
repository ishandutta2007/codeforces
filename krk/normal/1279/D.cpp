#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 1000005;

int n, k;
int cnt[Maxn];
int w[Maxn];
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k; scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int a; scanf("%d", &a);
            cnt[a]++; w[a] = (w[a] + Inv(k)) % mod;
        }
    }
    for (int i = 0; i < Maxn; i++) if (cnt[i] > 0)
        res = (res + ll(cnt[i]) * w[i]) % mod;
    res = ll(res) * Inv(n) % mod * Inv(n) % mod;
    printf("%d\n", res);
    return 0;
}