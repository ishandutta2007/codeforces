#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 5e5 + 5;

struct atom {
    int l, r, col;
    atom (int k1 = 0, int k2 = 0, int k3 = 0) : l(k1), r(k2), col(k3) {}
    bool operator < (const atom A) const { return l < A.l; }
};

set <atom> all;
set <atom> :: iterator it;
int a[N], id[N], ans[N], now[N];
int n, maxn;

struct seg_t {
    int sum[N << 2];
    vector <int> res;

    void modify(int u, int l, int r, int x) {
        ++sum[u];
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (mid >= x) modify(u << 1, l, mid, x);
        else modify(u << 1 | 1, mid + 1, r, x);
    }

    void query(int u, int L, int R, int l, int r) {
        if (sum[u] == R - L + 1) return;
        if (L == R) {
            res.push_back(L);
            return;
        }
        int mid = (L + R) >> 1;
        if (mid >= l) query(u << 1, L, mid, l, r);
        if (mid + 1 <= r) query(u << 1 | 1, mid + 1, R, l, r);
    }

    void query(int l, int r) {
        if (l > r) return;
        res.clear();
        query(1, 1, n, l, r);
        // fprintf(stderr, "l = %d, r = %d, res.size() = %d\n", l, r, (int)res.size());
        for (int i = 0; i < (int)res.size(); i++) modify(1, 1, n, res[i]);
    }
} tr;

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), id[i] = i;
    if (n == 1) {
        print(0, '\n');
        print(a[1], '\n');
        return 0;
    }
    all.insert(atom(1, n, 0));
    sort(id + 1, id + n + 1, cmp);
    for (int L = 1, R; L <= n; L = R + 1) {
        R = L;
        while (R < n && a[id[L]] == a[id[R + 1]]) ++R;
        for (int _ = L; _ <= R; _++) {
            int i = id[_];
            int con = 0;
            now[i] = 1;
            if (i != 1 && !now[i - 1]) con = 1;
            if (i != n && !now[i + 1]) con = 1;
            if (i == 1 || i == n) con = 1;
            if (con) {
                it = --all.upper_bound(atom(i));
                int l = it -> l, r = it -> r;
                // fprintf(stderr, "_ = %d, l = %d, r = %d\n", _, l, r);
                all.erase(it);
                if (i - 1 > l || (i - 1 >= l && l == 1)) all.insert(atom(l, i - 1, 0));
                if (i + 1 < r || (i + 1 <= r && r == n)) all.insert(atom(i + 1, r, 0));
            }
            int l = i, r = i;
            if ((i >= 3 && now[i - 1] && now[i - 2]) || (i == 2 && now[i - 1])) {
                it = --all.lower_bound(atom(i));
                l = it -> l; all.erase(it);
            } else if (i != 1 && now[i - 1]) l = i - 1;
            if ((i <= n - 2 && now[i + 1] && now[i + 2]) || (i == n - 1 && now[i + 1])) {
                it = all.lower_bound(atom(i));
                r = it -> r; all.erase(it);
            } else if (i != n && now[i + 1]) r = i + 1;
            // fprintf(stderr, "_ = %d, i = %d, l = %d, r = %d\n", _, i, l, r);
            if (l != r || (i == 1 || i == n)) all.insert(atom(l, r, 1));
        }
        for (int _ = L; _ <= R; _++) {
            int i = id[_];
            vector <atom> seq;
            it = all.upper_bound(atom(i));
            for (int j = 1; j <= 2; j++) {
                if (it == all.end()) break;
                seq.push_back(*it);
                ++it;
            }
            it = all.upper_bound(atom(i));
            for (int j = 1; j <= 3; j++) {
                if (it == all.begin()) break;
                --it;
                seq.push_back(*it);
            }
            sort(seq.begin(), seq.end());
            // fprintf(stderr, "_ = %d :\n", _);
            for (int j = 0; j < (int)seq.size(); j++) {
                // fprintf(stderr, "l = %d, r = %d, col = %d\n", seq[j].l, seq[j].r, seq[j].col);
                if (seq[j].col) {
                    tr.query(seq[j].l, seq[j].r);
                    for (int k = 0; k < (int)tr.res.size(); k++) ans[tr.res[k]] = a[i];
                }
            }
            for (int j = 1; j < (int)seq.size(); j++) {
                if (seq[j - 1].col && seq[j].col) {
                    tr.query(seq[j - 1].r + 1, seq[j].l - 1);
                    maxn = max(maxn, (seq[j].l - seq[j - 1].r) / 2);
                    for (int k = 0; k < (int)tr.res.size(); k++) ans[tr.res[k]] = a[i];
                    continue;
                }
                if (!seq[j - 1].col && !seq[j].col) {
                    maxn = max(maxn, (seq[j].l - seq[j - 1].r) / 2);
                    continue;
                }
                int l = seq[j - 1].r + 1, r = seq[j].l - 1, mid = (l + r) >> 1;
                maxn = max(maxn, (r - l + 1) / 2);
                if (seq[j - 1].col) tr.query(l, mid);
                else tr.query(mid + 1, r);
                for (int k = 0; k < (int)tr.res.size(); k++) ans[tr.res[k]] = a[i];
            }
        }
    }
    print(maxn, '\n');
    for (int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
    return 0;
}