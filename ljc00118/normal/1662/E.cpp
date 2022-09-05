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

int f[N], a[N], pos[N];
int T, n; ll ans;

void add(int x, int y) {
    while (x <= n) {
        f[x] += y;
        x += (x & -x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += f[x];
        x &= (x - 1);
    }
    return ans;
}

int main() {
    read(T);
    while (T--) {
        ans = 0;
        read(n);
        for (int i = 1; i <= n; i++) {
            read(a[i]); pos[a[i]] = i;
            f[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            int cnt;
            if (pos[i - 1] < pos[i]) {
                cnt = query(pos[i]) - query(pos[i - 1]);
            } else {
                cnt = i - 2 - query(pos[i - 1]) + query(pos[i]);
            }
            ans += 1ll * cnt * (n - i + 1);
            add(pos[i - 1], 1);
        }
        print(ans, '\n');
    }
    return 0;
}