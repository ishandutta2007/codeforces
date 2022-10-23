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

int a[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        if (n % 2 == 1) {
            print(-1, '\n');
            continue;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i += 2) {
            if (a[i] == a[i + 1]) {
                cnt += 1;
            } else {
                cnt += 2;
            }
        }
        print(cnt, '\n');
        for (int i = 1; i <= n; i += 2) {
            if (a[i] == a[i + 1]) {
                printf("%d %d\n", i, i + 1);
            } else {
                printf("%d %d\n%d %d\n", i, i, i + 1, i + 1);
            }
        }
    }
    return 0;
}