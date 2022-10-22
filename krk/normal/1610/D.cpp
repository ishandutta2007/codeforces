#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxb = 30;

int n;
int hm[Maxb];

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
    scanf("%d", &n);
    int res = 1;
    for (int i = 0; i < n; i++)
        res = 2ll * res % mod;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        if (a % 2) continue;
        int b = 0;
        while (!(a & 1 << b)) b++;
        hm[b]++;
    }
    int sub = 1;
    for (int i = 0; i < Maxb; i++) if (hm[i]) {
        int cur = toPower(2, hm[i] - 1) % mod;
        int rem = 0;
        for (int j = i + 1; j < Maxb; j++)
            rem += hm[j];
        sub = (sub + ll(cur) * toPower(2, rem)) % mod;
    }
    res = (res - sub + mod) % mod;
    printf("%d\n", res);
    return 0;
}