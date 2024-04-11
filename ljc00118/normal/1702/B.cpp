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

char c[N];
int vis[26];
int T, n;

int main() {
    read(T);
    while (T--) {
        scanf("%s", c + 1); n = strlen(c + 1);
        int ans = 0;
        for (int l = 1, r; l <= n; l = r + 1) {
            r = l;
            int now = 1;
            memset(vis, 0, sizeof(vis)); vis[c[l] - 'a'] = 1;
            while (r < n && (now != 3 || vis[c[r + 1] - 'a'])) {
                if (!vis[c[r + 1] - 'a']) {
                    vis[c[r + 1] - 'a'] = 1;
                    ++now;
                }
                ++r;
            }
            ++ans;
        }
        print(ans, '\n');
    }
    return 0;
}