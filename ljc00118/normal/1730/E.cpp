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

const int N = 1e6 + 5;

vector <int> g[N];
int a[N], x[N], y[N], cnt[N];
int T, n; ll ans;

void solve(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    x[mid] = y[mid] = a[mid];
    x[mid + 1] = y[mid + 1] = a[mid + 1];
    for (int i = mid - 1; i >= l; i--) {
        x[i] = min(a[i], x[i + 1]);
        y[i] = max(a[i], y[i + 1]);
    }
    for (int i = mid + 2; i <= r; i++) {
        x[i] = min(a[i], x[i - 1]);
        y[i] = max(a[i], y[i - 1]);
    }
    int p1 = mid, p2 = mid, ret = 0;
    for (int i = mid + 1; i <= r; i++) {
        while (p1 >= l && y[p1] <= y[i]) {
            if (y[i] % x[p1] == 0) ++ret;
            ++cnt[x[p1]]; --p1;
        }
        while (p2 >= l && x[p2] >= x[i]) {
            if (y[i] % x[p2] == 0) --ret;
            --p2;
        }
        if (y[i] % x[i] == 0) ans += mid - max(p1, p2);
        if (i == mid + 1 || y[i] != y[i - 1]) {
            ret = 0;
            for (auto j : g[y[i]]) {
                if (j >= x[i]) break;
                ret += cnt[j];
            }
        }
        ans += max(ret, 0);
    }
    while (p1 < mid) {
        ++p1;
        --cnt[x[p1]];
    }
    p1 = mid + 1; p2 = mid + 1; ret = 0;
    for (int i = mid; i >= l; i--) {
        while (p1 <= r && y[p1] < y[i]) {
            if (y[i] % x[p1] == 0) ++ret;
            ++cnt[x[p1]]; ++p1;
        }
        while (p2 <= r && x[p2] >= x[i]) {
            if (y[i] % x[p2] == 0) --ret;
            ++p2;
        }
        if (y[i] % x[i] == 0) ans += min(p1, p2) - mid - 1;
        if (i == mid || y[i] != y[i + 1]) {
            ret = 0;
            for (auto j : g[y[i]]) {
                if (j >= x[i]) break;
                ret += cnt[j];
            }
        }
        ans += max(ret, 0);
    }
    while (p1 > mid + 1) {
        --p1;
        --cnt[x[p1]];
    }
    solve(l, mid); solve(mid + 1, r);
}

int main() {
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) g[j].push_back(i);
    }
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        ans = n; solve(1, n);
        print(ans, '\n');
    }
    return 0;
}