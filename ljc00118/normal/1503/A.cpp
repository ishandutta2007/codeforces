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

char s[N];
int a[N], b[N];
int T, n, nowa, nowb;

int main() {
    read(T);
    while (T--) {
        read(n); scanf("%s", s + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) cnt += (s[i] == '1');
        if (cnt & 1) {
            printf("NO\n");
            continue;
        }
        int nowcnt = 0, cando = 1;
        nowa = nowb = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                ++nowcnt;
                if (nowcnt <= cnt / 2) {
                    ++nowa; ++nowb;
                    a[i] = b[i] = 1;
                } else {
                    --nowa; --nowb;
                    a[i] = b[i] = 0;
                    if (nowa < 0 || nowb < 0) {
                        cando = 0;
                    }
                }
            } else {
                if (nowa <= nowb) {
                    ++nowa; --nowb;
                    a[i] = 1; b[i] = 0;
                } else {
                    ++nowb; --nowa;
                    a[i] = 0; b[i] = 1;
                }
                if (nowa < 0 || nowb < 0) {
                    cando = 0;
                }
            }
        }
        if (!cando) {
            printf("NO\n");
        } else {
            printf("YES\n");
            for (int i = 1; i <= n; i++) {
                if (a[i] == 1) putchar('(');
                else putchar(')');
            }
            putchar('\n');
            for (int i = 1; i <= n; i++) {
                if (b[i] == 1) putchar('(');
                else putchar(')');
            }
            putchar('\n');
        }
    }
    return 0;
}