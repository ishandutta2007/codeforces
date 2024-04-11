#include<bits/stdc++.h>
using namespace std;
const int L = 2e5;
const int MX = 1e5 + 10;
const int S = 86;
const int MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return int64_t(a) * b % MOD;
}

template <typename T>
struct fast_segtree {
    /// This is 0-index segment tree
    int n;
    T t[MX * 2];

    void set_n(int n) {
        this->n = n;
    }

    void pull (int v) {
        t[v >> 1] = max(t[v], t[v ^ 1]);
    }

    void update_0(int v, T val) {
        for (t[v += n] = val ; v > 1 ; v >>= 1) {
            pull(v);
        }
    }

    T query_0(int l, int r) {

        T res = t[l + n];
        for (l += n, r += n ; l < r ; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l ++]);
            if (r & 1) res = max(res, t[-- r]);
        }
        return res;
    }

    void update(int v, T val) {
        update_0(v - 1, val);
    }

    T get(int l, int r) {
        -- l;
        return query_0(l, r);
    }
};
int sg[MX * 40];
int lc[MX * 40];
int rc[MX * 40];
int root[MX];
int tot;


void build(int &v, int x, int y) {
    ++ tot;
    sg[tot] = 1;
    lc[tot] = lc[v];
    rc[tot] = rc[v];
    v = tot;
    if (x == y) {
        return ;
    } else {
        int mid = x + y >> 1;
        build(lc[v], x, mid);
        build(rc[v], mid + 1, y);
        sg[v] = 1;
    }
}

void update(int &v, int x, int y, int pos, int val) {
    ++ tot;
    sg[tot] = sg[v];
    lc[tot] = lc[v];
    rc[tot] = rc[v];
    v = tot;
    if (x == y) {
        sg[v] = val;
    } else {
        int mid = x + y >> 1;
        if (pos <= mid) update(lc[v], x, mid, pos, val);
        else update(rc[v], mid + 1, y, pos, val);
        sg[v] = mul(sg[lc[v]], sg[rc[v]]);
    }
}

int get(int v, int x, int y, int l, int r) {
    if (l == x && r == y) {
        return sg[v];
    } else {
        int mid = x + y >> 1;
        if (r <= mid) return get(lc[v], x, mid, l, r);
        else if (l > mid) return get(rc[v], mid + 1, y, l, r);
        else {
            int foo = get(lc[v], x, mid, l, mid);
            int bar = get(rc[v], mid + 1, y, mid + 1, r);
            return mul(foo, bar);
        }
    }
}


fast_segtree <char> fast_sg[S]; /// Or sparse table if TLE
vector <int> primes;
bool is_prime[L + 10];
int lst[L + 10];
int pw[S][25];
int n;

void precalc() {
    fill(is_prime + 2, is_prime + L + 1, true);
    for (int i = 2 ; i <= L ; ++ i) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        if (primes.size() == S) break;
        for (int j = i + i ; j <= L ; j += i)
            is_prime[j] = false;
    }
    for (int i = 0 ; i < S ; ++ i) {
        int bar = primes[i];
        pw[i][0] = 1;
        for (int j = 1 ; j < 25 ; ++ j)
            pw[i][j] = mul(pw[i][j - 1], bar);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    precalc();

    cin >> n;

    for (int i = 0 ; i < S ; ++ i)
        fast_sg[i].set_n(n);

    build(root[0], 1, n);

    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        cin >> x;
        for (int j = 0 ; j < S ; ++ j) {
            int cnt = 0;
            int y = primes[j];
            while (x % y == 0) {
                cnt += 1;
                x /= y;
            }
            if (cnt) fast_sg[j].update(i, cnt);
        }
        root[i] = root[i - 1];
        if (x != 1) {
            if (lst[x] == 0) {
                update(root[i], 1, n, i, x);
            } else {
                update(root[i], 1, n, lst[x], 1);
                update(root[i], 1, n, i, x);
            }
            lst[x] = i;
        }
    }

    int fuck = 0;
    int nq;
    cin >> nq;

    for (; nq -- ;) {
        int l, r;
        cin >> l >> r;
        ((l += fuck) %= n)++;
        ((r += fuck) %= n)++;
        if (l > r) swap(l, r);
        fuck = get(root[r], 1, n, l, r);
        for (int i = 0 ; i < S ; ++ i) {
            int c = fast_sg[i].get(l, r);
            fuck = mul(fuck, pw[i][c]);
        }
        cout << fuck << '\n';
    }
}