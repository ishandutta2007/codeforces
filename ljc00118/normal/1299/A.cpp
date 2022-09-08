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

int a[N], cnt[32];
int n, ans, res = -1;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        for (int j = 0; j <= 30; j++) {
            if ((a[i] >> j) & 1) ++cnt[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        int now = 0;
        for (int j = 0; j <= 30; j++) {
            if ((a[i] >> j) & 1) {
                if (cnt[j] == 1) {
                    now |= (1 << j);
                }
            }
        }
        if (now > res) ans = i, res = now;
    }
    swap(a[1], a[ans]);
    for (int i = 1; i <= n; i++) print(a[i], i == n ? '\n' : ' ');
    return 0;
}