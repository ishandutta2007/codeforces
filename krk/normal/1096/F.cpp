#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;

int inv[Maxn];
int n;
int P[Maxn];
int L[Maxn], R[Maxn];
int LV[Maxn], RV[Maxn];
bool tk[Maxn];
int BIT[Maxn];
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

void Insert(int x)
{
    for (int i = x; i > 0; i -= i & -i)
        BIT[i]++;
}

int Get(int x)
{
    int res = 0;
    for (int i = x; i <= n; i += i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    for (int i = 1; i < Maxn; i++)
        inv[i] = Inv(i);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &P[i]);
        if (P[i] == -1) L[i] = L[i - 1] + 1;
        else {
            L[i] = L[i - 1];
            tk[P[i]] = true;
            res = (res + Get(P[i])) % mod;
            Insert(P[i]);
        }
    }
    for (int i = 1; i <= n; i++)
        LV[i] = LV[i - 1] + !tk[i];
    for (int i = n; i > 0; i--)
        RV[i] = RV[i + 1] + !tk[i];
    for (int i = n; i > 0; i--)
        R[i] = R[i + 1] + (P[i] == -1);
    res = (res + ll(L[n]) * (L[n] - 1) / 2 % mod * inv[2]) % mod;
    for (int i = 1; i <= n; i++)
        if (P[i] != -1) {
            int tot = L[i] + R[i];
            res = (ll(res) + ll(LV[P[i]]) * R[i] % mod * inv[tot] +
                             ll(RV[P[i]]) * L[i] % mod * inv[tot]) % mod;
        }
    printf("%d\n", res);
    return 0;
}