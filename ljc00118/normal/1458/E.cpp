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

const int N = 2e5 + 5;

pair <pii, int> q[N];
pii a[N];
set <int> all, bad;
int b[N], ans[N];
int n, m, blen, rs;

int nxt = -1;
void update(int cnt) {
    if (!cnt) return;
    nxt = -1;
    while (all.size()) {
        auto it = all.begin();
        if (*it - rs - 1 < cnt) {
            cnt -= (*it - rs - 1);
            rs = *it;
            all.erase(it);
        } else {
            rs += cnt; cnt = 0;
            break;
        }
    }
    if (cnt) rs += cnt;
}

void getnxt() {
    if (nxt != -1) return;
    int las = rs;
    for (auto it = all.begin(); it != all.end(); ++it) {
        if (*it != las + 1) break;
        las = *it;
    }
    nxt = las + 1;
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(a[i].first), read(a[i].second), b[++blen] = a[i].first;
    for (int i = 1; i <= m; i++) read(q[i].first.first), read(q[i].first.second), q[i].second = i, b[++blen] = q[i].first.first;
    sort(a + 1, a + n + 1); sort(q + 1, q + m + 1);
    sort(b + 1, b + blen + 1); blen = unique(b + 1, b + blen + 1) - b - 1;
    rs = b[0] = -1;
    for (int i = 1, alen = 1, qlen = 1; i <= blen; i++) {
        update(b[i] - b[i - 1] - 1);
        getnxt();
        int isbad = 1, must_bad = 0;
        bad.clear();
        while (alen <= n && a[alen].first == b[i]) {
            if (a[alen].second < nxt) isbad = 0;
            if (a[alen].second == nxt) must_bad = 1;
            bad.insert(a[alen].second);
            if (a[alen].second > rs) all.insert(a[alen].second);
            ++alen;
        }
        isbad |= must_bad;
        if (isbad) all.erase(nxt), bad.insert(nxt), update(1);
        // {
        //     fprintf(stderr, "row = %d, rs = %d, bad = {", b[i], rs);
        //     int flag = 0;
        //     for (auto it = bad.begin(); it != bad.end(); ++it) {
        //         if (flag) fprintf(stderr, ", ");
        //         flag = 1; fprintf(stderr, "%d", *it);
        //     }
        //     fprintf(stderr, "}\n");
        // }
        while (qlen <= m && q[qlen].first.first == b[i]) {
            if (bad.find(q[qlen].first.second) == bad.end()) ans[q[qlen].second] = 1;
            ++qlen;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (ans[i]) printf("WIN\n");
        else printf("LOSE\n");
    }
    return 0;
}