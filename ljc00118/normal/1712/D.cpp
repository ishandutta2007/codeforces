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

const int N = 1e5 + 5;

int a[N], b[N], dp[N];
int T, n, k;

int main() {
    read(T);
    while (T--) {
        read(n); read(k);
        for (int i = 1; i <= n; i++) read(a[i]);
        int l = 1, r = 1e9, ans = 1;
        while (l <= r) {
            int mid = (l + r) >> 1, cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] * 2 < mid) {
                    ++cnt;
                    b[i] = 1e9;
                } else {
                    b[i] = a[i];
                }
            }
            int minn = 2;
            for (int i = 1; i < n; i++) {
                minn = min(minn, (int)(b[i] < mid) + (int)(b[i + 1] < mid));
            }
            if (cnt + minn <= k) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        print(ans, '\n');
    }
    return 0;
}