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

const int N = 2e6 + 5;

int a[N], cnt[N];
int n, ans;

void dfs(int u, int x) {
    if(cnt[x] == 2) return;
    if(u == -1) { ++cnt[x]; return; }
    dfs(u - 1, x);
    if((x >> u) & 1) dfs(u - 1, x ^ (1 << u));
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]);
    for(register int i = n; i >= 1; i--) {
        int now = 0;
        if(i <= n - 2) {
            for(register int j = 20; j >= 0; j--) {
                if(((a[i] >> j) & 1) == 0) {
                    if(cnt[now ^ (1 << j)] == 2) now ^= (1 << j);
                }
            }
            ans = max(ans, a[i] ^ now);
        }
        dfs(20, a[i]);
    }
    print(ans, '\n');
    return 0;
}