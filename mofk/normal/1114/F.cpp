#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

typedef pair <long long, long long> dat;

dat operator * (const dat &a, const dat &b) {
    return {a.first * b.first % mod, a.second | b.second};
}

int n, q;
dat t[2000006], lz[2000006];
int inv[305];
bool cps[305];
int pr[65], mul[65], npr;
long long f[305];

dat pw(dat x, int y) {
    --y;
    long long mul = x.first;
    while (y) {
        if (y & 1) x.first = mul * x.first % mod;
        mul = mul * mul % mod;
        y >>= 1;
    }
    return x;
}

void push(int node, int l, int r) {
    t[node] = t[node] * pw(lz[node], r - l + 1);
    if (l < r) {
        lz[node * 2] = lz[node * 2] * lz[node];
        lz[node * 2 + 1] = lz[node * 2 + 1] * lz[node];
    }
    lz[node] = {1, 0};
}

void up(int node, int l, int r, int u, int v, dat x) {
    push(node, l, r);
    if (r < u || l > v) return;
    if (u <= l && r <= v) {
        lz[node] = lz[node] * x;
        push(node, l, r);
        return;
    }
    int m = l + r >> 1;
    up(node * 2, l, m, u, v, x);
    up(node * 2 + 1, m + 1, r, u, v, x);
    t[node] = t[node * 2] * t[node * 2 + 1];
}

dat get(int node, int l, int r, int u, int v) {
    push(node, l, r);
    if (r < u || l > v) return {1, 0};
    if (u <= l && r <= v) return t[node];
    int m = l + r >> 1;
    return get(node * 2, l, m, u, v) * get(node * 2 + 1, m + 1, r, u, v);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    inv[1] = 1;
    for (int i = 2; i <= 300; ++i) inv[i] = (mod - 1LL * (mod / i) * inv[mod % i] % mod) % mod;
    for (int i = 2; i <= 300; ++i) if (!cps[i]) {
        pr[npr] = i;
        mul[npr] = 1LL * (i - 1) * inv[i] % mod;
        for (int j = i; j <= 300; j += i) cps[j] = 1, f[j] |= (1LL << npr);
        ++npr;
    }

    cin >> n >> q;
    for (int i = 0; i < 2000006; ++i) t[i] = lz[i] = {1, 0};
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        up(1, 1, n, i, i, {x, f[x]});
    }

    while (q--) {
        string cmd; cin >> cmd;
        if (cmd[0] == 'M') {
            int l, r, x;
            cin >> l >> r >> x;
            up(1, 1, n, l, r, {x, f[x]});
        }
        else {
            int l, r;
            cin >> l >> r;
            dat ans = get(1, 1, n, l, r);
            long long ret = ans.first;
            for (int i = 0; i < npr; ++i) if (ans.second >> i & 1)
                ret = ret * mul[i] % mod;
            cout << ret << '\n';
        }
    }
    return 0;
}