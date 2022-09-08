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

const int N = 1e5 + 5;

int st[N][20], go[N][20], mn[N][20];
int a[N], lg[N];
int n, all, flag = 1;

int query(int l, int r) {
    int k = lg[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int query2(int l, int r) {
    if(l <= r) return query(l, r);
    return max(query(l, n), query(1, r));
}

int qry(int l, int r) {
    int k = lg[r - l + 1];
    return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}

int qry2(int l, int r) {
    if(l <= r) return qry(l, r);
    return min(qry(l, n), qry(1, r));
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), st[i][0] = a[i], mn[i][0] = a[i], go[i][0] = a[i] * 2 + 1, all = max(all, a[i]);
    for(register int i = 1; i <= n; i++) {
        if(all > a[i] * 2) {
            flag = 0;
            break;
        }
    }
    if(flag) {
        for(register int i = 1; i <= n; i++) {
            print(-1, i == n ? '\n' : ' ');
        }
        return 0;
    }
    for(register int j = 1; j <= 19; j++) {
        for(register int i = 1; i <= n - (1 << j) + 1; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        }
    }
    lg[0] = -1;
    for(register int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
    for(register int j = 1; j <= 19; j++) {
        if((1 << j) >= n) continue;
        for(register int i = 1; i <= n; i++) {
            int midl = (i + (1 << (j - 1)) - 2) % n + 1;
            int midr = (i + (1 << (j - 1)) - 1) % n + 1;
            go[i][j] = go[i][j - 1];
            if(go[i][j - 1] == -1) continue;
            int mx = query2(i, midl);
            if(mx >= go[midr][j - 1]) {
                go[i][j] = -1;
                continue;
            }
            go[i][j] = min(go[i][j], go[midr][j - 1]);
        }
    }
    for(register int i = 1; i <= n; i++) {
        int now = i, mx = a[i], dis = 1;
        for(register int j = 19; j >= 0; j--) {
            if(dis + (1 << j) > n) continue;
            if(go[now % n + 1][j] == -1) continue;
            if(mx >= go[now % n + 1][j]) continue;
            mx = max(mx, query2(now % n + 1, (now + (1 << j) - 1) % n + 1));
            now = (now + (1 << j) - 1) % n + 1; dis += (1 << j);
        }
        if(dis == n) {
            for(register int j = 19; j >= 0; j--) {
                if(dis + (1 << j) > 2 * n) continue;
                if(mx > qry2(now % n + 1, (now + (1 << j) - 1) % n + 1) * 2) continue;
                now = (now + (1 << j) - 1) % n + 1; dis += (1 << j);
            }
        }
        print(dis, i == n ? '\n' : ' ');
    }
    return 0;
}