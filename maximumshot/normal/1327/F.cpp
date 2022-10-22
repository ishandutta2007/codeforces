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

struct Fen {
    int n; // [0, n)
    vector<int> f;

    Fen(int n): n(n) {
        f.resize(n);
    }

    void put(int pos, int val) {
        for (int cur = pos; cur < n; cur |= (cur + 1))
            _inc(f[cur], val);
    }

    int get(int pos) {
        int res = 0;
        for (int cur = pos; cur >= 0; cur = (cur & (cur + 1)) - 1)
            _inc(res, f[cur]);
        return res;
    }

    int get(int l, int r) {
        if (l < 0) l = 0;
        if (r >= n) r = n - 1;
        if (l > r)
            return 0;
        return _sub(get(r), get(l - 1));
    }
};

const int N = 5e5 + 5;

int pw2[N];
int r2 = _binpow(2, mod - 2);
int pw_r2[N];

void precalc() {
    pw2[0] = 1;
    pw_r2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw2[i] = _mul(pw2[i - 1], 2);
        pw_r2[i] = _mul(pw_r2[i - 1], r2);
    }
}

struct Restriction {
    int l, r, x;

    void read() {
        cin >> l >> r >> x;
        l--, r--;
    }
};

int n, k, m;
Restriction rs[N];

void read() {
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        rs[i].read();
    }
}


mt19937 rnd(42);
void gen() {
    const int MAXK = 5;
    const int MAXN = 6;
    const int MAXM = 10;
    // k = rnd() % MAXK + 1;
    // n = rnd() % MAXN + 1;
    // m = rnd() % MAXM;
    k = 30;
    n = m = 5e5 + 5;
    for (int i = 0; i < m; i++) {
        rs[i].r = rnd() % n;
        rs[i].l = rnd() % (rs[i].r + 1);
        rs[i].x = 0;
    }
}

int a[N];
pii segs[N];
int ss;
int pos[N], nxt[N], prv[N];
vector<int> ls[N];
int dp[N];

int fast01() {
    int sz = 0;
    for (int i = 0; i < n; i++) {
        if (a[i])
            pos[i] = sz++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i])
            nxt[i] = i;
        else
            nxt[i] = i + 1 < n ? nxt[i + 1] : n;
    }
    for (int i = 0; i < n; i++) {
        if (a[i])
            prv[i] = i;
        else
            prv[i] = i ? prv[i - 1] : -1;
    }
    for (int i = 0; i < ss; i++) {
        int l, r;
        tie(l, r) = segs[i];
        l = nxt[l], r = prv[r];
        if (l > r)
            return 0;
        segs[i] = {pos[l], pos[r]};
    }
    if (!ss) {
        return pw2[sz];
    }
    for (int i = 0; i < sz; i++)
        ls[i].clear();
    for (int i = 0; i < ss; i++) {
        ls[segs[i].second].push_back(segs[i].first);
    }
    fill(dp, dp + n, 0);
    int mx_l = -1;
    int cur_sum = 1;
    for (int i = 0; i < sz; i++) {
        _inc(dp[i], cur_sum);
        _inc(cur_sum, dp[i]);
        for (int l : ls[i]) {
            while (mx_l < l) {
                _dec(cur_sum, mx_l == -1 ? 1 : dp[mx_l]);
                mx_l++;
            }
        }
    }

    int res = 0;
    for (int j = mx_l; j < sz; j++) {
        _inc(res, dp[j]);
    }

    return res;
}

int fast() {
    int res = 1;
    for (int j = 0; j < k; j++) {
        fill(a, a + n, 0);
        ss = 0;
        for (int i = 0; i < m; i++) {
            if (((1 << j) & rs[i].x)) {
                a[rs[i].l]++;
                if (rs[i].r + 1 < n)
                    a[rs[i].r + 1]--;
            } else {
                segs[ss++] = {rs[i].l, rs[i].r};
            }
        }
        for (int i = 1; i < n; i++)
            a[i] += a[i - 1];
        for (int i = 0; i < n; i++)
            a[i] = !(a[i] > 0);
        res = _mul(res, fast01());
    }
    return res;
}

int st[N];

void rec(int ptr, int &res) {
    if (ptr == n) {
        int ok = 1;
        for (int i = 0; i < m; i++) {
            int _and = (1 << k) - 1;
            for (int j = rs[i].l; j <= rs[i].r; j++) {
                _and &= st[j];
            }
            if (_and != rs[i].x) {
                ok = 0;
                break;
            }
        }
        if (ok)
            _inc(res, 1);
        return;
    }
    for (st[ptr] = 0; st[ptr] < (1 << k); st[ptr]++) {
        rec(ptr + 1, res);
    }
}

int slow() {
    int res = 0;
    rec(0, res);
    return res;
}

void work() {
    read();
//    gen();
    cout << fast() << "\n";
//    cout << slow() << "\n";
}

void test() {
    while (1) {
        gen();

        int fs = fast();
        int sl = slow();

        if (fs == sl) {
            cout << "OK\n";
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << "\n";
            cout << n << " " << k << " " << m << "\n";
            for (int i = 0; i < m; i++) {
                cout << rs[i].l + 1 << " " << " " << rs[i].r + 1 << " " << rs[i].x << "\n";
            }
            break;
        }

        cout << endl;
    }
}

int main() {

    precalc();

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
//
    work();
//    test();

    return 0;
}