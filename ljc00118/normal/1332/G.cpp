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

set <int> all;
set <int> :: iterator it;
int a[N], st1[N], st2[N], cnt[N], l[N], lg[N], ans[N][4], up[N], down[N];
int n, q, top1, top2, len1, len2;

void update(int u) {
    ++cnt[u];
    if (cnt[u] == 2) all.insert(u);
}

struct st_table {
    int mx[N][18], mn[N][18], wz_mx[N][18], wz_mn[N][18], v[N];

    void build() {
        for (int i = 1; i <= n; i++) mx[i][0] = mn[i][0] = v[i], wz_mx[i][0] = wz_mn[i][0] = i;
        for (int j = 1; j <= 17; j++) {
            for (int i = 1; i <= n - (1 << j) + 1; i++) {
                if (mx[i][j - 1] > mx[i + (1 << (j - 1))][j - 1]) mx[i][j] = mx[i][j - 1], wz_mx[i][j] = wz_mx[i][j - 1];
                else mx[i][j] = mx[i + (1 << (j - 1))][j - 1], wz_mx[i][j] = wz_mx[i + (1 << (j - 1))][j - 1];
                if (mn[i][j - 1] < mn[i + (1 << (j - 1))][j - 1]) mn[i][j] = mn[i][j - 1], wz_mn[i][j] = wz_mn[i][j - 1];
                else mn[i][j] = mn[i + (1 << (j - 1))][j - 1], wz_mn[i][j] = wz_mn[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int query_mx(int l, int r) {
        int k = lg[r - l + 1];
        if (mx[l][k] > mx[r - (1 << k) + 1][k]) return wz_mx[l][k];
        return wz_mx[r - (1 << k) + 1][k];
    }

    int query_mn(int l, int r) {
        int k = lg[r - l + 1];
        if (mn[l][k] < mn[r - (1 << k) + 1][k]) return wz_mn[l][k];
        return wz_mn[r - (1 << k) + 1][k];
    }
} s1, s2;

int main() {
    read(n); read(q);
    lg[0] = -1;
    for (int i = 1; i <= n; i++) read(a[i]), lg[i] = lg[i >> 1] + 1;
    memcpy(s1.v, a, sizeof(s1.v)); s1.build();
    for (int i = 1; i <= n; i++) {
        int tmp1 = top1, tmp2 = top2;
        while (top1 && a[st1[top1]] < a[i]) --top1;
        while (top2 && a[st2[top2]] > a[i]) --top2;
        if (top1 && top2) {
            int l = 1, r = top1, res = -1, pos;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (a[st1[mid]] != a[i]) res = mid, l = mid + 1;
                else r = mid - 1;
            }
            if (res == -1) goto naive;
            pos = st1[res];
            l = 1; r = top2; res = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (a[st2[mid]] != a[i]) res = mid, l = mid + 1;
                else r = mid - 1;
            }
            if (res == -1) goto naive;
            pos = min(pos, st2[res]);
            it = all.lower_bound(pos);
            if (it != all.begin()) {
                --it;
                s2.v[i] = *it;
                ans[i][0] = *it; ans[i][3] = i;
                ans[i][1] = s1.query_mx(*it + 1, i - 1);
                ans[i][2] = s1.query_mn(*it + 1, i - 1);
                // if (a[ans[i][1]] <= a[i] || a[ans[i][2]] >= a[i]) s2.v[i] = ans[i][0] = 0;
                if (ans[i][1] > ans[i][2]) swap(ans[i][1], ans[i][2]);
            }
        }
        naive:;
        for (int i = top1 + 1; i <= tmp1; i++) update(st1[i]);
        for (int i = top2 + 1; i <= tmp2; i++) update(st2[i]);
        st1[++top1] = i; st2[++top2] = i;
    }
    s2.build();
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i + 1]) up[++len1] = i;
        if (a[i] > a[i + 1]) down[++len2] = i;
    }
    while (q--) {
        int l, r;
        read(l); read(r);
        int pos = s2.query_mx(l, r);
        if (ans[pos][0] >= l) {
            print(4, '\n');
            for (int i = 0; i <= 3; i++) print(ans[pos][i], i == 3 ? '\n' : ' ');
            continue;
        }
        int pos1 = lower_bound(up + 1, up + len1 + 1, r) - up - 1;
        int pos2 = lower_bound(down + 1, down + len2 + 1, r) - down - 1;
        if (pos1 && pos2 && up[pos1] >= l && down[pos2] >= l) {
            int minn = min(up[pos1], down[pos2]), maxn = max(up[pos1], down[pos2]);
            print(3, '\n');
            print(minn, ' '); print(minn + 1, ' ' ); print(maxn + 1, '\n');
        } else {
            print(0, '\n');
            putchar('\n');
        }
    }
    return 0;
}