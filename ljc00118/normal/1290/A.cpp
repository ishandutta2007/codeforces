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

const int N = 3505, INF = 0x7fffffff;

int a[N];
int T, n, m, k, ans;

int main() {
    read(T);
    while (T--) {
        read(n); read(m); read(k); k = min(k, m - 1); ans = 0;
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 0; i <= k; i++) {
            int minn = INF;
            for (int j = 0; j <= m - 1 - k; j++) {
                minn = min(minn, max(a[i + j + 1], a[n - (k - i) - (m - 1 - k - j)]));
            }
            ans = max(ans, minn);
        }
        print(ans, '\n');
    }
    return 0;
}