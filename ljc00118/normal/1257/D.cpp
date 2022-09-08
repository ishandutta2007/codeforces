#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;

struct ele {
    int p, s;
    ele (int a = 0, int b = 0) : p(a), s(b) {}
    bool operator < (const ele A) const { return p < A.p; }
} p[N];

int st[N][20], a[N], lg[N], s[N];
int T, n, m, now, res;

int query(int l, int r) {
    int k = lg[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

bool check(int l, int r) {
    int val = query(l, r);
    if(val > p[m].p) return 0;
    int pos = lower_bound(p + 1, p + m + 1, ele(val, 0)) - p;
    return s[pos] >= r - l + 1;
}

int main() {
    read(T);
    while(T--) {
        read(n);
        for(register int i = 1; i <= n; i++) read(a[i]), st[i][0] = a[i];
        for(register int j = 1; j < 20; j++) {
            for(register int i = 1; i <= n - (1 << j) + 1; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
        lg[0] = -1;
        for(register int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
        read(m);
        for(register int i = 1; i <= m; i++) read(p[i].p), read(p[i].s);
        sort(p + 1, p + m + 1);
        s[m] = p[m].s;
        for(register int i = m - 1; i >= 1; i--) s[i] = max(s[i + 1], p[i].s);
        now = 1; res = 0;
        while(now <= n) {
            int l = now, r = n, ans = -1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(check(now, mid)) ans = mid, l = mid + 1;
                else r = mid - 1;
            }
            if(ans == -1) {
                res = -1;
                break;
            }
            ++res; now = ans + 1;
        }
        print(res, '\n');
    }
    return 0;
}