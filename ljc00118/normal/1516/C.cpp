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

const int N = 105, M = 100000;

int a[N], f[M + 5];
int n;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    while (1) {
        int cando = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] % 2 == 1) {
                cando = 0;
            }
        }
        if (!cando) break;
        for (int i = 1; i <= n; i++) a[i] >>= 1;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    if (sum & 1) {
        printf("0\n");
        return 0;
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = M; j >= a[i]; j--) f[j] |= f[j - a[i]];
    }
    if (!f[sum / 2]) {
        printf("0\n");
        return 0;
    }
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 1) {
            pos = i;
            break;
        }
    }
    printf("1\n%d\n", pos);
    return 0;
}