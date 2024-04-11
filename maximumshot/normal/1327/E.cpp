#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void _inc(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void _dec(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int _binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int _div(int a, int b) {
    return _mul(a, _binpow(b, mod - 2));
}

int slow(int n, int k) {
    int mx = (int) pow(10, n);
    int res = 0;
    for (int x = 0; x < mx; x++) {
        vector<int> a;
        for (int y = x, j = 0; j < n; j++, y /= 10)
            a.push_back(y % 10);
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && a[i] == a[j])
                j++;
            j--;
            int len = j - i + 1;
            if (len == k)
                res++;
            i = j;
        }
    }
    return res;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = _mul(pw[i - 1], 10);
    }

    for (int i = 1; i <= n; i++) {
        int res = 0;

        if (i + 2 <= n) {
            int ml = _mul(9, 9);
            ml = _mul(ml, pw[n - i - 1]);
            _inc(res, _mul(ml, n - i - 1));
        }

        if (i + 1 <= n) {
            int ml = _mul(2, 9);
            ml = _mul(ml, pw[n - i]);
            _inc(res, ml);
        }

        if (i == n) {
            _inc(res, 10);
        }

        cout << res << " ";
//        cout << slow(n, i) << "\n";
    }
    cout << "\n";

    return 0;
}