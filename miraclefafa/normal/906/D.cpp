#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 101000;
int n, q, m, p[100], a[N], t;

ll powmod(ll a,ll b,ll mod) {
    ll res=1;a%=mod;
    assert(b>=0);
    for(;b;b>>=1) {
        if(b&1)res=res*a%mod;
        a=a*a%mod;
    }
    return res;
}
ll phi(int p) {
    int phip = p, q = p;
    for (int i = 2; i * i <= q; i++) if (q % i == 0) {
        phip = phip / i * (i - 1);
        while (q % i == 0) q /= i;
    }
    if (q != 1) phip = phip / q * (q - 1);
    return phip;
}

int solve(int l, int r, int x) {
    int q = p[x];
    if (l == r) return a[l];
    if (q == 1) return 1;
    int d = solve(l + 1, r, x + 1);
    int ans = powmod(a[l], d, p[x]);
    bool isles = true;
    // a[l] ^ d < q
    if (a[l] != 1) {
        if (d >= 30) isles = false;
        else if (pow(a[l], d) >= 1e9) isles = false;
        else {
            int val = powmod(a[l], d, 1000000007);
            if (val >= q) isles = false;
        }
    }
    if (!isles) ans += q;
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    p[t++] = m;
    while (p[t - 1] != 1) {
        p[t] = phi(p[t - 1]);
        t += 1;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", solve(l, r, 0) % m);
    }
}