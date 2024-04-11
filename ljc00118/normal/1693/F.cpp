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
int las[N * 2], s[N];
int T, n, ans;

int main() {
    read(T);
    while (T--) {
        read(n); scanf("%s", c + 1); ans = 0;
        int cnt[2] = {0, 0};
        for (int i = 1; i <= n; i++) ++cnt[c[i] - '0'];
        for (int i = 0; i <= 2 * n; i++) las[i] = 0;
        if (cnt[0] < cnt[1]) {
            for (int i = 1; i <= n; i++) {
                if (c[i] == '0') c[i] = '1';
                else c[i] = '0';
            }
            reverse(c + 1, c + n + 1);
        }
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + (c[i] == '1' ? 1 : -1);
            las[s[i] + n] = i;
            // fprintf(stderr, "las[%d] = %d\n", s[i] + n, i);
        }
        int now = 1, len = 1;
        while (now <= n && c[now] != '1') ++now;
        if (now == n + 1) {
            print(0, '\n');
            continue;
        }
        while (now < n && c[now + 1] == '1') ++now, ++len;
        while (now < n) {
            ++ans;
            if (len + s[n] - s[now] >= 0) break;
            int tmp = las[s[now] - len + n];
            len = (tmp - now + len) / 2; now = tmp;
            while (now < n && c[now + 1] == '1') ++now, ++len;
        }
        print(ans, '\n');
    }  
    return 0;
}