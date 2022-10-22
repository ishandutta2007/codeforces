#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = inf + 7;

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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
//        int res = 0;
//        for (int mask = 0; mask < (1 << n); mask++) {
//            int x = 0, y = 0;
//            for (int i = 0; i < n; i++) {
//                if ((1 << i) & mask) {
//                    x |= (1 << (a[i + 1] - 1));
//                    y |= (1 << (b[i + 1] - 1));
//                }
//            }
//            if (x == y)
//                res++;
//        }
//        cout << res << "\n";

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) p[a[i]] = b[i];
        vector<int> used(n + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (used[i])
                continue;
            for (int x = i; !used[x]; x = p[x]) {
                used[x] = 1;
            }
            cnt++;
        }
        cout << _binpow(2, cnt) << "\n";
    }

    return 0;
}