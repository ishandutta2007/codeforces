#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int K = 10005;

int k;
long long m, n, l = 1, mx = 0, a[K];
vector<long long> re, mo;

int power(long long x, long long pr) {
    if (x == 0) {
        return K;
    }
    if (x < 0) {
        x = -x;
    }
    int cnt = 0;
    for (; x % pr == 0; x /= pr) {
        cnt++;
    }
    return cnt;
}

bool solve(long long pr, int cnt) {
    int pos = 0;
    for (int i = 1; i <= k; i++) {
        if (power(a[i], pr) == cnt) {
            pos = i;
            break;
        }
    }
    for (int i = 1; i <= k; i++) {
        if (power(a[i], pr) != min(cnt, power(i - pos, pr))) {
            return false;
        }
    }
    long long cur = pow(pr, cnt);
    mo.push_back(cur);
    re.push_back((k - pos) % cur);
    return true;
}

long long euclid(long long a, long long b, long long &x, long long &y) {
    long long xx = y = 0;
    long long yy = x = 1;
    while (b > 0) {
        long long q = a / b;
        long long t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}

pair<long long, long long> crt(long long r1, long long m1, long long r2, long long m2) {
    long long s, t;
    long long g = euclid(m1, m2, s, t);
    long long M = m1 / g * m2;
    return {(s * r2 % M * (m1 / g) + t * r1 % M * (m2 / g)) % M, M};
}

pair<long long, long long> crt(const vector<long long> &r, const vector<long long> &m) {
    pair<long long, long long> ret = {0, 1};
    int n = m.size();
    for(int i = 0; i < n; i++) {
        ret = crt(ret.fi, ret.se, r[i], m[i]);
    }
    (ret.fi += ret.se) %= ret.se;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        mx = max(mx, a[i] + k - i);
        long long g = __gcd(l, a[i]);
        if (l / g > m / a[i]) {
            return cout << "NO", 0;
        }
        l = l / g * a[i];
    }
    for (int i = 2; 1LL * i * i <= l; i++) {
        if (l % i == 0) {
            int cnt = 0;
            for (; l % i == 0; l /= i) {
                cnt++;
            }
            if (!solve(i, cnt)) {
                return cout << "NO", 0;
            }
        }
    }
    if (l > 1 && !solve(l, 1)) {
        return cout << "NO", 0;
    }
    pair<long long, long long> ret = crt(re, mo);
    if (ret.fi < mx) {
        ret.fi += (((mx - ret.fi - 1) / ret.se) + 1) * ret.se;
    }
    if (ret.fi > n) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}