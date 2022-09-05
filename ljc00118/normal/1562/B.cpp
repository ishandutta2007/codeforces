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
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

const int N = 55, M = 7777;

char c[N];
int isp[M + 5], val[N];
int T, n;

bool check(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    for (int i = 2; i <= M; i++) isp[i] = check(i);
    read(T);
    while (T--) {
        read(n); scanf("%s", c + 1);
        for (int i = 1; i <= M; i++) {
            if (isp[i]) continue;
            int len = 0, tmp = i;
            while (tmp) {
                val[++len] = tmp % 10;
                tmp /= 10;
            }
            reverse(val + 1, val + len + 1);
            int pos = 1;
            for (int j = 1; j <= n; j++) {
                if (c[j] - '0' == val[pos]) ++pos;
                if (pos == len + 1) break;
            }
            if (pos == len + 1) {
                print(len, '\n');
                print(i, '\n');
                break;
            }
        }
    }
    return 0;
}