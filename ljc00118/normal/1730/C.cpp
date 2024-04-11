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

char c[N];
int cnt[10], ans[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", c + 1); n = strlen(c + 1);
        int minn = 10;
        for (int i = n; i >= 1; i--) {
            int x = c[i] - '0';
            if (x > minn) ans[i] = 0, ++cnt[min(x + 1, 9)];
            else ans[i] = 1, minn = x;
        }
        int now = 0;
        for (int i = 1; i <= n; i++) {
            if (!ans[i]) continue;
            while (1) {
                while (now <= 9 && !cnt[now]) ++now;
                if (now <= 9 && now <= c[i] - '0') {
                    print(now); --cnt[now];
                } else {
                    break;
                }
            }
            print(c[i] - '0');
        }
        while (1) {
            while (now <= 9 && !cnt[now]) ++now;
            if (now > 9) break;
            print(now); --cnt[now];
        }
        putchar('\n');
    }
    return 0;
}