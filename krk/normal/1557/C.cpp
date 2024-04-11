#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 1000000007;

int pw2[Maxn];
int T;
int n, k;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int main()
{
    pw2[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw2[i] = 2ll * pw2[i - 1] % mod;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        int res = 0;
        int cur = 1;
        for (int i = k - 1; i >= 0; i--) {
            int ncur = 0;
            if (n % 2 == 0) {
                res = (res + ll(cur) * toPower(pw2[i], n)) % mod;
                ncur = (ncur + ll(pw2[n - 1] - 1ll + mod) % mod * cur) % mod;
            } else {
                ncur = (ncur + cur) % mod;
                ncur = (ncur + ll(pw2[n - 1]) * cur) % mod;
            }
            cur = ncur;
        }
        res = (res + cur) % mod;
        printf("%d\n", res);
    }
    return 0;
}