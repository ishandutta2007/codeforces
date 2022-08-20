/*
    28.12.2018 18:14:22
*/

#include <bits/stdc++.h>

using namespace std;

vector< long long > t;
int n0;

void init (int nn) {
    n0 = nn;
    t.assign (n0, 0);
}

long long sum (int r) {
    long long result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1) {
        result += t[r];
    }
    return result;
}

void inc (int i, int delta) {
    for (; i < n0; i = (i | (i+1))) {
        t[i] += delta;
    }
}

long long sum (int l, int r) {
    return sum (r) - sum (l-1);
}

long long gcd (long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

long long gcd(long long a, long long b) {
    long long x, y;
    return gcd(a, b, x, y);
}

long long mod = 998244353;

int main() {
    int n;
    cin >> n;
    vector< long long > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != -1) {
            --a[i];
        }
    }
    vector< long long > bef(n, 0), aft(n, 0);
    bef[0] = a[0] == -1;
    aft[n - 1] = a[n - 1] == -1;
    for (int i = 1; i < n; ++i) {
        bef[i] = bef[i - 1];
        if (a[i] == -1) {
            ++bef[i];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        aft[i] = aft[i + 1];
        if (a[i] == -1) {
            ++aft[i];
        }
    }
    long long sm = 0;
    vector< bool > u(n, false);
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            u[a[i]] = true;
        }
    }
    vector< long long > nubef(n, 0), nuaft(n, 0);
    nubef[0] = !u[0];
    nuaft[n - 1] = !u[n - 1];
    for (int i = 1; i < n; ++i) {
        nubef[i] = nubef[i - 1] + 1;
        if (u[i]) {
            --nubef[i];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        nuaft[i] = nuaft[i + 1] + 1;
        if (u[i]) {
            --nuaft[i];
        }
    }
    // print(bef);
    // print(aft);
    // print(nubef);
    // print(nuaft);
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            sm += bef[i] * nuaft[a[i]] + aft[i] * nubef[a[i]];
        }
    }
    long long cnt = aft[0];
    long long inv = 0;
    vector< int > b;
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            b.push_back(a[i]);
        }
    }
    int m = b.size();
    init(n + 5);
    for (int i = 0; i < m; ++i) {
        inv += sum(b[i], n);
        inc(b[i], 1);
    }
    if (cnt == 0) {
        cout << inv % mod << '\n';
    } else {
        sm += inv * cnt;
        sm = sm * 2 + cnt * cnt * (cnt - 1) / 2;
        cnt *= 2;
        long long d = gcd(min(sm, cnt), max(cnt, sm));
        cnt /= d;
        sm /= d;
        // cout << inv << ' ' << sm << ' ' << cnt << '\n';
        long long x, y;
        gcd(cnt, mod, x, y);
        sm %= mod;
        x = ((x % mod) + mod) % mod;
        cout << sm * x % mod << '\n';
    }
    return 0;
}