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

struct Fen {
    int n = 0; // [0, n)
    vector<ll> f;

    Fen() = default;

    Fen(int nn) {
        n = nn;
        f.resize(n);
    }

    void add(int pos, ll value) {
        for (int cur = pos; cur < n; cur |= (cur + 1))
            f[cur] += value;
    }

    ll get(int pos) {
        ll res = 0;
        for (int cur = pos; cur >= 0; cur = (cur & (cur + 1)) - 1)
            res += f[cur];
        return res;
    }
};

const int MAXX = 3e5 + 10;

struct RangeTree {
    int n = 0; // [0, n)
    vector<ll> t;

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        t.assign(4 * n, 0);
    }

    void push(int v) {
        t[v << 1] += t[v];
        t[v << 1 | 1] += t[v];
        t[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, ll x) {
        if (l <= tl && tr <= r) {
            t[v] += x;
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm)
                update(v << 1, tl, tm, l, r, x);
            if (r > tm)
                update(v << 1 | 1, tm + 1, tr, l, r, x);
        }
    }

    void update(int l, int r, ll x) {
        update(1, 0, n - 1, l, r, x);
    }

    void put(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            t[v] = 0;
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (pos <= tm)
                put(v << 1, tl, tm, pos);
            else
                put(v << 1 | 1, tm + 1, tr, pos);
        }
    }

    void put(int i) {
        put(1, 0, n - 1, i);
    }

    ll get(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            return t[v];
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (pos <= tm)
                return get(v << 1, tl, tm, pos);
            else
                return get(v << 1 | 1, tm + 1, tr, pos);
        }
    }

    ll get(int i) {
        return get(1, 0, n - 1, i);
    }
};

vector<ll> slow(int n, vector<int> a) {
    vector<ll> res(n + 1);
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                res[k] += a[i] % a[j];
            }
        }
    }
    return res;
}

vector<ll> fast(int n, vector<int> a) {
    vector<ll> res(n + 1);
    Fen sm(MAXX), cn(MAXX);
    vector<int> was(MAXX);
    ll total_sum = 0;
    vector<int> where(MAXX);
    for (int i = 1; i <= n; i++)
        where[a[i]] = i;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        res[i] = res[i - 1];
        ll cnt = i - 1 - cn.get(a[i]);
        ll sum = sm.get(a[i]);
        res[i] += 1ll * cnt * a[i] + sum;
        cn.add(a[i], +1);
        sm.add(a[i], +a[i]);
        res[i] += 1ll * x * (i - 1 - cnt);
//        for (int y = 1; y < a[i]; y++) {
//            if (0 < where[y] && where[y] < where[x])
//                res[i] += - (x / y) * y;
//        }
        res[i] += 1ll * (total_sum - sum);
        total_sum += x;

        ll tmp = 0;
        for (int y = x; y < MAXX; y += x) {
            int ny = min(MAXX - 1, y + x - 1);
            int hlp = cn.get(ny) - cn.get(y - 1) - (y == x);
//            for (int yy = y; yy <= ny; yy++)
//                hlp += was[yy];
            tmp += -1ll * (y / x) * hlp;
        }
        res[i] += tmp * x;
        was[a[i]] = 1;
    }
    vector<ll> add(MAXX);
    RangeTree rt(MAXX);
    vector<ll> add2(n + 1);
    for (int i = n; i >= 1; i--) {
        int y = a[i];
//        for (int x = y + 1; x < MAXX; x++) {
//            if (0 < where[y] && where[y] < where[x])
//                add2[where[x]] += - 1ll * (x / y) * y;
//        }
        for (int k = 1, x = y; x < MAXX; x += y, k++) {
            int nx = min(MAXX - 1, x + y - 1);
            if (x <= nx)
                rt.update(x, nx, -1ll * k * y);
//            for (int xx = x; xx <= nx; xx++) {
//                add[xx] += - 1ll * k * y;
//            }
        }
//        add[y] = 0;
        rt.put(y);
    }
    for (int x = 0; x < MAXX; x++) {
        add2[where[x]] = rt.get(x);
//        add2[where[x]] = add[x];
    }
    add2[0] = 0;
    for (int i = 1; i <= n; i++) {
        add2[i] += add2[i - 1];
        res[i] += add2[i];
    }
    return res;
}

void work() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<ll> res = fast(n, a);
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << "\n";
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 4;
    while (1) {
        int n = rnd() % MAXN + 1;
        vector<int> a(10 * n + 1);
        for (int i = 0; i < (int) a.size(); i++)
            a[i] = i;
        shuffle(a.begin() + 1, a.end(), rnd);
        a.resize(n + 1);
        vector<ll> fs = fast(n, a);
        vector<ll> sl = slow(n, a);
        if (fs == sl) {
            cout << "OK( "; for (int i = 1; i <= n; i++) cout << fs[i] << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = "; for (int i = 1; i <= n; i++) cout << sl[i] << " "; cout << "\n";
            cout << "fnd = "; for (int i = 1; i <= n; i++) cout << fs[i] << " "; cout << "\n";
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