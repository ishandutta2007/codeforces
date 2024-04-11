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

int a[10], b[N];
int n, ans = 2e9;

int main() {
    for (int i = 1; i <= 6; i++) read(a[i]);
    read(n);
    for (int i = 1; i <= n; i++) read(b[i]);
    sort(a + 1, a + 6 + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            int minn = b[i] - a[j], maxn = minn;
            vector <int> pos(6, 0);
            for (int k = 1; k <= 6; k++) {
                pos[k - 1] = lower_bound(b + 1, b + n + 1, a[k] + minn) - b;
            }
            if (pos[0] != 1) continue;
            for (int k = 0; k < 6; k++) {
                int r = n;
                if (k != 5) r = pos[k + 1] - 1;
                maxn = max(maxn, b[r] - a[k + 1]);
            }
            ans = min(ans, maxn - minn);
        }
    }
    print(ans, '\n');
    return 0;
}