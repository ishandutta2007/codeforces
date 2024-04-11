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

const int N = 1e5 + 5;

int a[N];
int T, n, sum;

int main() {
    read(T);
    while (T--) {
        read(n); sum = 0;
        for (int i = 1; i <= n; i++) read(a[i]), sum += a[i];
        if (sum % n != 0) {
            printf("-1\n");
            continue;
        }
        print(3 * n - 3, '\n');
        for (int i = 2; i <= n; i++) {
            printf("1 %d %d\n", i, i - ((a[i] - 1) % i + 1));
            printf("%d 1 %d\n", i, (a[i] - 1) / i + 1);
        }
        for (int i = 2; i <= n; i++) printf("1 %d %d\n", i, sum / n);
    }
    return 0;
}