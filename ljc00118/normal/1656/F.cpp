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

const int N = 2e5 + 5;

int a[N], f[N], go[N]; __int128 val[N]; ll val2[N];
int T, n; ll ans;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

pair <__int128, ll> calc(ll mid) {
    for (int i = 1; i <= n; i++) f[i] = i;
    __int128 ans1 = 0; ll ans2 = 0;
    int blocks = n;
    while (blocks > 1) {
        for (int i = 1; i <= n; i++) val[i] = 1e30;
        auto solve = [&](int id) {
            if (id < 1 || id > n) return;
            for (int i = 1; i <= n; i++) {
                if (find(i) == find(id)) continue;
                __int128 now = 1ll * a[id] * a[i] + (__int128)(a[id] + a[i]) * mid;
                if (now < val[find(i)]) {
                    val[find(i)] = now;
                    val2[find(i)] = a[id] + a[i];
                    go[find(i)] = find(id);
                }
            }
        };
        int pos = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < 0) pos = i;
        }
        solve(1); solve(pos); solve(pos + 1); solve(n);
        for (int i = 2; i <= pos; i++) {
            if (find(i) != find(1)) {
                solve(i);
                break;
            }
        }
        for (int i = pos - 1; i >= 1; i--) {
            if (find(i) != find(pos)) {
                solve(i);
                break;
            }
        }
        for (int i = pos + 2; i <= n; i++) {
            if (find(i) != find(pos + 1)) {
                solve(i);
                break;
            }
        }
        for (int i = n - 1; i >= pos + 1; i--) {
            if (find(i) != find(n)) {
                solve(i);
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (find(i) == i) {
                if (find(i) != find(go[i])) {
                    f[find(i)] = find(go[i]);
                    ans1 += val[i];
                    ans2 += val2[i];
                    --blocks;
                }
            }
        }
    }
    return make_pair(ans1, ans2);
}

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        sort(a + 1, a + n + 1);
        ll sum1 = 1ll * a[n] * (n - 1), sum2 = 1ll * a[1] * (n - 1);
        for (int i = 1; i <= n - 1; i++) sum1 += a[i];
        for (int i = 2; i <= n; i++) sum2 += a[i];
        if (sum1 < 0 || sum2 > 0) {
            printf("INF\n");
            continue;
        }
        pair <ll, ll> t = calc(0);
        if (t.second < 0) {
            for (int i = 1; i <= n; i++) a[i] = -a[i];
            reverse(a + 1, a + n + 1);
        }
        ll l = 1, r = 4e18, res = 0;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (calc(mid).first >= calc(mid - 1).first) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        print(calc(res).first, '\n');
    }
    return 0;
}