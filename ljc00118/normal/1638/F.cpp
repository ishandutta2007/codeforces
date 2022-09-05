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

const int N = 10005;

ll a[N], s1[N], s2[N], p1[N], p2[N], v1[N], v2[N], ans;
int l[N], r[N], st[N], id[N];
int n, top, len1, len2;

bool cmp(int i, int j) { return a[i] < a[j]; }

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        while (top && a[i] <= a[st[top]]) --top;
        if (top) l[i] = st[top];
        else l[i] = 0;
        st[++top] = i;
    }
    top = 0;
    for (int i = n; i >= 1; i--) {
        while (top && a[i] <= a[st[top]]) --top;
        if (top) r[i] = st[top];
        else r[i] = n + 1;
        st[++top] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j < r[i]; j++) s1[j] = max(s1[j], (j - l[i]) * a[i]);
        for (int j = i; j > l[i]; j--) s2[j] = max(s2[j], (r[i] - j) * a[i]);
    }
    for (int i = 1; i <= n; i++) s1[i] = max(s1[i - 1], s1[i]);
    for (int i = n; i >= 1; i--) s2[i] = max(s2[i + 1], s2[i]);
    for (int i = 1; i <= n; i++) ans = max(ans, s1[i] + s2[i + 1]);

    for (int i = 1; i <= n; i++) {
        ll base = (r[i] - l[i] - 1) * a[i], now = a[i];
        int L = l[i], R = r[i];
        while (a[L] || a[R]) {
            now = max(a[L], a[R]);
            while (L > 0 && a[L] >= now) --L;
            while (R <= n && a[R] >= now) ++R;
            ans = max(ans, base + (R - L - (r[i] - l[i])) * now);
        }
    }

    for (int i = 1; i <= n; i++) {
        len1 = len2 = 0;
        for (int j = 1; j <= n; j++) {
            if (id[j] <= l[i] && r[id[j]] >= r[i]) {
                ll val = (r[i] - l[id[j]] - 1) * a[id[j]];
                ++len1;
                p1[len1] = id[j];
                v1[len1] = max(v1[len1 - 1], val);
            }
            if (id[j] >= r[i] && l[id[j]] <= l[i]) {
                ll val = (r[id[j]] - l[i] - 1) * a[id[j]];
                ++len2;
                p2[len2] = id[j];
                v2[len2] = max(v2[len2 - 1], val);
            }
        }
        for (int j = 1, k = len2; j <= len1; j++) {
            while (k && a[p1[j]] + a[p2[k]] > a[i]) --k;
            if (k) ans = max(ans, v1[j] + v2[k]);
            if (k != len2) ans = max(ans, v1[j] + (r[p2[k + 1]] - l[i] - 1) * (a[i] - a[p1[j]]));
        }
        for (int j = 1, k = len1; j <= len2; j++) {
            while (k && a[p2[j]] + a[p1[k]] > a[i]) --k;
            if (k != len1) ans = max(ans, v2[j] + (r[i] - l[p1[k + 1]] - 1) * (a[i] - a[p2[j]]));
        }
    }

    print(ans, '\n');
    return 0;
}