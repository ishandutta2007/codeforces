#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 3e5 + 5, MAXN = 1e9;

struct ele {
    int l, r, t;
    ele (int a = 0, int b = 0, int c = 0) : l(a), r(b), t(c) {}
    bool operator < (const ele A) const { return l < A.l; }
};

set <ele> all;
set <ele> :: iterator it;
vector <pii> opt[N];
int l[N], r[N], cnt[N];
int n, m;

void split(int pos) {
    if (pos == 0) return;
    it = all.upper_bound(ele(pos)); --it;
    if (it -> r == pos) return;
    int l = it -> l, r = it -> r, t = it -> t;
    all.erase(it);
    all.insert(ele(l, pos, t));
    all.insert(ele(pos + 1, r, t));
}

bool check(int mid) {
    memset(cnt, 0, sizeof(cnt));
    ll ans = 0; cnt[0] = MAXN;
    for (int i = 1, j = 0, now = MAXN; i <= n; i++) {
        for (int _ = 0; _ < (int)opt[i].size(); _++) {
            cnt[opt[i][_].first] += opt[i][_].second;
            if (opt[i][_].first >= j) now += opt[i][_].second;
        }
        while (now - cnt[j] >= mid) now -= cnt[j], ++j;
        ans += j;
    }
    return ans >= m;
}

struct fenwick {
    ll f[N];

    void add(int x, ll y) {
        ++x;
        while (x <= n + 1) {
            f[x] += y;
            x += (x & -x);
        }
    }

    ll query(int x) {
        ++x;
        ll ans = 0;
        while (x) {
            ans += f[x];
            x &= (x - 1);
        }
        return ans;
    }
} tr1, tr2;

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(l[i]), read(r[i]), --r[i];
    all.insert(ele(1, MAXN, 0));
    for (int i = 1; i <= n; i++) {
        split(l[i] - 1);
        split(r[i]);
        while (1) {
            it = all.lower_bound(ele(l[i]));
            if (it == all.end() || it -> l > r[i]) break;
            opt[i].push_back(make_pair(it -> t, -(it -> r - it -> l + 1)));
            all.erase(it);
        }
        all.insert(ele(l[i], r[i], i));
        opt[i].push_back(make_pair(i, r[i] - l[i] + 1));
    }
    int l = 1, r = MAXN, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    assert(ans);
    ll sum1 = 0, sum2 = 0;
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = MAXN; tr1.add(0, MAXN);
    for (int i = 1, j = 0, now = MAXN; i <= n; i++) {
        for (int _ = 0; _ < (int)opt[i].size(); _++) {
            cnt[opt[i][_].first] += opt[i][_].second;
            tr1.add(opt[i][_].first, opt[i][_].second);
            tr2.add(opt[i][_].first, 1ll * opt[i][_].second * opt[i][_].first);
            if (opt[i][_].first >= j) now += opt[i][_].second;
        }
        while (now - cnt[j] >= ans) now -= cnt[j], ++j;
        sum1 += (MAXN - tr1.query(j)) * j + tr2.query(j);
        sum2 += j;
    }
    print(sum1 - (sum2 - m) * ans, '\n');
    return 0;
}