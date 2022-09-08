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

const int N = 2e6 + 5;

char c[N], t[N];
int dis[N];
int T, n, len;

int manacher() {
    int ans = 0, pos = 0, id = 0;
    for (int i = 1; i <= len; i++) {
        int x = (pos > i ? min(dis[id * 2 - i], pos - i) : 1);
        while (t[i - x] == t[i + x]) ++x;
        if (i + (dis[i] = x) > pos) pos = i + x, id = i;
        if (dis[i] == i) ans = max(ans, i);
    }
    return ans;
}

int main() {
    read(T);
    while (T--) {
        scanf("%s", c + 1); n = strlen(c + 1);
        int l = 1, r = n;
        while (l <= r) {
            if (c[l] == c[r]) {
                ++l; --r;
            } else {
                break;
            }
        }
        if (l > r) {
            printf("%s\n", c + 1);
            continue;
        }
        t[len = 0] = '('; t[++len] = c[l];
        for (int i = l + 1; i <= r; i++) t[++len] = '!', t[++len] = c[i];
        t[len + 1] = ')';
        int now1 = manacher();
        reverse(t + 1, t + len + 1);
        int now2 = manacher();
        for (int i = 1; i < l; i++) putchar(c[i]);
        if (now1 > now2) {
            for (int i = l; i <= l + now1 - 1; i++) putchar(c[i]);
        } else {
            for (int i = r - now2 + 1; i <= r; i++) putchar(c[i]);
        }
        for (int i = r + 1; i <= n; i++) putchar(c[i]);
        putchar('\n');
    }
    return 0;
}