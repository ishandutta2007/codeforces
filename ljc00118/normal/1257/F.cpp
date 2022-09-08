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

const int N = 105, MAXN = 1 << 15;

int trie[MAXN * 105][35], val[MAXN * 105];
int a[N], tmp[N];
int n, tot, h, lh;

int main() {
    read(n); h = 15; lh = 30 - h;
    for(register int i = 1; i <= n; i++) read(a[i]);
    for(register int t = 0; t < (1 << h); t++) {
        int now = 0;
        for(register int i = 1; i <= n; i++) {
            int x = __builtin_popcount((a[i] & ((1 << h) - 1)) ^ t);
            if(!trie[now][x]) trie[now][x] = ++tot;
            now = trie[now][x];
        }
        val[now] = t;
    }
    for(register int t = 0; t < (1 << lh); t++) {
        for(register int i = 1; i <= n; i++) tmp[i] = __builtin_popcount((a[i] >> h) ^ t);
        for(register int cnt = 0; cnt <= 30; cnt++) {
            int now = 0, ok = 1;
            for(register int i = 1; i <= n; i++) {
                if(cnt - tmp[i] < 0) {
                    ok = 0;
                    break;
                }
                if(!trie[now][cnt - tmp[i]]) {
                    ok = 0;
                    break;
                }
                now = trie[now][cnt - tmp[i]];
            }
            if(ok) {
                print(val[now] ^ (t << h), '\n');
                return 0;
            }
        }
    }
    print(-1, '\n');
    return 0;
}