#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 200005;

int n;
int L[Maxn];
int R[Maxn];
int P[Maxn], sumP[Maxn];
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

int Inv(int x) { return toPower(x, mod - 2); }

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &L[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &R[i]);
    for (int i = 1; i <= n; i++) {
        int lef = max(L[i - 1], L[i]);
        int rig = min(R[i - 1], R[i]);
        if (lef > rig) P[i] = 0;
        else P[i] = ll(rig - lef + 1) * Inv(R[i - 1] - L[i - 1] + 1) % mod * Inv(R[i] - L[i] + 1) % mod;
        P[i] = (1 - P[i] + mod) % mod;
    }
    for (int i = 1; i <= n; i++) {
        sumP[i] = (sumP[i - 1] + P[i]) % mod;
        res = (res + P[i]) % mod;
        if (i >= 2) {
            int lef = max(L[i - 2], max(L[i - 1], L[i]));
            int rig = min(R[i - 2], min(R[i - 1], R[i]));
            int sam = 0;
            if (lef <= rig)
                sam = ll(rig - lef + 1) * Inv(R[i - 2] - L[i - 2] + 1) % mod *
                                          Inv(R[i - 1] - L[i - 1] + 1) % mod *
                                          Inv(R[i] - L[i] + 1) % mod;
            int add = 1ll;
            add = (add - (1 + mod - P[i - 1]) % mod + mod) % mod;
            add = (add - (1 + mod - P[i]) % mod + mod) % mod;
            add = (add + sam) % mod;
            res = (res + 2ll * ll(add)) % mod;
            res = (res + 2ll * ll(P[i]) % mod * ll(sumP[i - 2])) % mod;
        }
    }
    printf("%d\n", res);
    return 0;
}