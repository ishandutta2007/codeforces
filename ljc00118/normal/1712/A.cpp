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

const int N = 105;

multiset <int> all;
int a[N], b[N];
int T, n, k;

int main() {
    read(T);
    while (T--) {
        all.clear();
        read(n); read(k);
        for (int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= k; i++) all.insert(b[i]);
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            if (all.find(a[i]) != all.end()) {
                all.erase(all.find(a[i]));
                ++ans;
            }
        }
        print(k - ans, '\n');
    }
    return 0;
}