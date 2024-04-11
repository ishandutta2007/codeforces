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

int s[N];
int T, n, c, ans;

int main() {
    read(T);
    while (T--) {
        ans = 1;
        read(n); read(c);
        for (int i = 1; i <= c; i++) s[i] = 0;
        for (int i = 1; i <= n; i++) {
            int x; read(x);
            ++s[x];
        }
        for (int i = 1; i <= c; i++) s[i] += s[i - 1];
        for (int i = 1; i <= c; i++) {
            if (s[i] == s[i - 1]) {
                for (int j = 1; j <= c / i; j++) {
                    if (s[j] != s[j - 1]) {
                        int l = i * j, r = min(c, (i + 1) * j - 1);
                        if (s[r] != s[l - 1]) {
                            ans = 0;
                        }
                    }
                }
            }
        }
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}