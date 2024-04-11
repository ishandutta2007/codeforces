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

map <int, int> cnt;
int a[N];
int T, n, x;

int main() {
    read(T);
    while (T--) {
        read(n); read(x);
        int ans = 0;
        cnt.clear();
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            if (cnt[x + a[i]] || cnt[a[i] - x]) {
                ans = 1;
            }
            cnt[a[i]] = 1;
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}