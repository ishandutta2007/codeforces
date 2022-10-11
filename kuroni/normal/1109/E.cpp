#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1E5 + 5, LG = 17;

int n, q, t, l, r, x, m, a[N];
vector<int> cnt;

struct segment_tree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1
    
    int tm, im, cp;
    long long su[4 * N], tru[4 * N];
    vector<int> mod, pr, cnt[4 * N];
    vector<vector<long long>> pw;
    
    void apply(int i, long long t, vector<int> &c) {
        bool neg = false;
        (tru[i] *= t) %= tm;
        (su[i] *= t) %= tm;
        for (int j = 0; j < cp; j++) {
            cnt[i][j] += c[j];
            if (c[j] < 0) {
                neg = true;
            } else {
                (su[i] *= pw[j][c[j]]) %= tm;
            }
        }
        if (neg) {
            su[i] = tru[i];
            for (int j = 0; j < cp; j++) {
                (su[i] *= pw[j][cnt[i][j]]) %= tm;
            }
        }
    }
    
    void down(int i) {
        apply(lc, tru[i], cnt[i]);
        apply(rc, tru[i], cnt[i]);
        tru[i] = 1;
        for (int &v : cnt[i]) {
            v = 0;
        }
    }
    
    void build(int l, int r, int i) {
        tru[i] = 1;
        for (int j = 0; j < cp; j++) {
            cnt[i].push_back(0);
        }
        if (l == r) {
            su[i] = 1;
            int tmp = a[l];
            for (int j = 0; j < cp; j++) {
                int v = pr[j];
                for (; tmp % v == 0; tmp /= v) {
                    cnt[i][j]++;
                }
                (su[i] *= pw[j][cnt[i][j]]) %= tm;
            }
            tru[i] = tmp % tm;
            (su[i] *= tmp) %= tm;
        } else {
            build(l, m, lc);
            build(m + 1, r, rc);
            su[i] = (su[lc] + su[rc]) % tm;
        }
    }
    
    void update(int l, int r, int i, int L, int R, long long t, vector<int> &c) {
        if (l > R || r < L || L > R) {
            return;
        } else if (L <= l && r <= R) {
            apply(i, t, c);
            return;
        } else {
            down(i);
            update(l, m, lc, L, R, t, c);
            update(m + 1, r, rc, L, R, t, c);
            su[i] = (su[lc] + su[rc]) % tm;
        }
    }
    
    long long query(int l, int r, int i, int L, int R) {
        if (l > R || r < L || L > R) {
            return 0;
        } else if (L <= l && r <= R) {
            return su[i];
        } else {
            down(i);
            return (query(l, m, lc, L, R) + query(m + 1, r, rc, L, R)) % tm;
        }
    }
    
    long long get_inverse(int u) {
        long long ret = 1;
        for (int i = __lg(im - 1); i >= 0; i--) {
            (ret *= ret) %= tm;
            if ((im - 1) >> i & 1) {
                (ret *= u) %= tm;
            }
        }
        return ret;
    }
    
    void add(int p, int mo) {
        cp++;
        pr.push_back(p);
        mod.push_back(mo);
        pw.push_back({1});
        for (int i = 1; i < N * LG; i++) {
            pw.back().push_back(pw.back().back() * p % tm);
        }
        (im /= p) *= (p - 1);
    }
    
#undef m
#undef lc
#undef rc
} seg;

void init() {
    seg.tm = seg.im = m;
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            int pr = i, cm = 1;
            for (; m % i == 0; m /= i) {
                cm *= pr;
            }
            seg.add(i, cm);
        }
    }
    if (m > 1) {
        seg.add(m, m);
    }
    seg.build(1, n, 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init();
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> l >> r >> x;
            cnt.clear();
            for (int &v : seg.pr) {
                int cur = 0;
                for (; x % v == 0; x /= v) {
                    cur++;
                }
                cnt.push_back(cur);
            }
            seg.update(1, n, 1, l, r, x, cnt);
        } else if (t == 2) {
            cin >> l >> x;
            cnt.clear();
            for (int &v : seg.pr) {
                int cur = 0;
                for (; x % v == 0; x /= v) {
                    cur++;
                }
                cnt.push_back(-cur);
            }
            seg.update(1, n, 1, l, l, seg.get_inverse(x), cnt);
        } else if (t == 3) {
            cin >> l >> r;
            cout << seg.query(1, n, 1, l, r) << '\n';
        }
    }
}