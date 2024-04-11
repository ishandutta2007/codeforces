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

int slow(int n, vector<int> a) {
    int res = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> ps, cs;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask) {
                ps.push_back(i + 1);
            } else {
                cs.push_back(i + 1);
            }
        }
        int ok = 1;
        for (int i = 1; i + 1 < (int) cs.size(); i++) {
            if (!(cs[i] - cs[i - 1] <= cs[i + 1] - cs[i]))
                ok = 0;
        }
        for (int i = 1; i + 1 < (int) ps.size(); i++) {
            if (!(ps[i] - ps[i - 1] >= ps[i + 1] - ps[i]))
                ok = 0;
        }
        ll S = 0;
        for (int i : cs) S += a[i];
        for (int i : ps) S -= a[i];
        ok &= S < 0;
        if (ok)
            _inc(res, 1);
    }
    return res;
}

struct Fen {
    int n = 0;
    vector<ll> crd;
    vector<int> f;

    Fen() = default;

    Fen(const vector<ll>& a) {
        crd = a;
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        n = (int) crd.size();
        f.resize(n);
    }

    void add(ll x) {
        int pos = lower_bound(crd.begin(), crd.end(), x) - crd.begin();
        pos = n - 1 - pos;
        for (int cur = pos; cur < n; cur |= (cur + 1))
            f[cur]++;
    }

    int query(ll x) {
        int pos = upper_bound(crd.begin(), crd.end(), x) - crd.begin();
        pos = n - 1 - pos;
        int res = 0;
        for (int cur = pos; cur >= 0; cur = (cur & (cur + 1)) - 1)
            res += f[cur];
        return res;
    }
};

int fast(int n, vector<int> a) {
    vector<ll> pr(n + 5);
    for (int i = 1; i <= n; i++)
        pr[i] = pr[i - 1] + a[i];
    vector<ll> sfP(n + 5);
    for (int i = n; i >= 1; i--) {
        sfP[i] = -sfP[i + 1] - a[i];
    }
    vector<ll> A(n + 5);
    for (int i = 1; i <= n; i++) {
        A[i] = sfP[i] - pr[i - 1];
    }
    int res = 1;
    Fen fen[2];
    fen[0] = Fen(A);
    fen[1] = Fen(A);

    fen[n % 2].add(A[n]);

    for (int x = n - 1; x >= 1; x--) {
        {
            ll S = pr[x];
            if ((n - x) % 2 == 0) {
                if (S + sfP[x + 1] < 0)
                    _inc(res, 1);
            }
            S += sfP[x + 1] - pr[n];
//            for (int i = x + 1; i <= n; i += 2) {
//                if (S < A[i])
//                    _inc(res, 1);
//            }
            _inc(res, fen[(x + 1) % 2].query(S));
        }
        {
            ll S = pr[x] + sfP[x + 1] - pr[n - 1] + a[n];
//            for (int i = x + 1; i <= n; i += 2) {
//                if (S < A[i])
//                    _inc(res, 1);
//            }
            _inc(res, fen[(x + 1) % 2].query(S));

            for (int i = max(x + 1, n - 1); i <= n; i++) {
                if (i % 2 == (x + 1) % 2) {
                    if (S < A[i])
                        _dec(res, 1);
                }
            }
        }
        {
            ll S = pr[x + 1] - 2 * a[1];
            if ((n - x - 1) % 2 == 0) {
                if (S + sfP[x + 2] < 0)
                    _inc(res, 1);
            }
            S += sfP[x + 2] - pr[n];

//            for (int i = x + 2; i <= n; i += 2) {
//                if (S < A[i])
//                    _inc(res, 1);
//            }
            _inc(res, fen[x % 2].query(S));
        }
        {
            ll S = pr[x + 1] - 2 * a[1] + sfP[x + 2] - pr[n - 1] + a[n];
//            for (int i = x + 2; i <= n; i += 2) {
//                if (S < A[i])
//                    _inc(res, 1);
//            }
            _inc(res, fen[x % 2].query(S));

            for (int i = max(x + 2, n - 1); i <= n; i++) {
                if (i % 2 == (x + 2) % 2) {
                    if (S < sfP[i] - pr[i - 1])
                        _dec(res, 1);
                }
            }
        }

        fen[x % 2].add(A[x]);
    }
    for (int x = 2; x < n; x++) {
        ll sumP = pr[x];
        ll sumC = pr[n] - pr[x];
        if (sumC < sumP)
            _inc(res, 1);
    }
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int fs = fast(n, a);
        cout << fs << "\n";
    }
}

void test() {
    const int MAXN = 16;
    const int MAXX = 3;
    mt19937 rnd(42);
    while (1) {
        int n = rnd() % MAXN + 1;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            a[i] = rnd() % MAXX + 1;
        auto fs = fast(n, a);
        auto sl = slow(n, a);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << n << "\n";
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}