#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int mod = 1000000007;
const int inv2 = (mod + 1) / 2;

int fac[Maxn];
int freq[Maxn];
int res = 1;

int main()
{
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++)
        fac[i] = ll(i) * fac[i - 1] % mod;
    int best = 0;
    int n; scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int c; scanf("%d", &c);
        freq[c]++;
        sum = (sum + c) % mod;
    }
    for (int i = Maxn; i > 0; i--)
        if (freq[i] > 0)
            if (i >= 2) {
                sum = (sum - 2ll * ll(freq[i]) % mod + mod) % mod;
                best = (best + ll(sum + sum + 2ll * freq[i]) % mod * freq[i] % mod * inv2 % mod * (i - 1)) % mod;
                res = ll(res) * fac[freq[i]] % mod * fac[freq[i]] % mod;
                freq[i - 2] += freq[i];
            } else res = ll(res) * fac[freq[i]] % mod;
    printf("%d %d\n", best, res);
    return 0;
}