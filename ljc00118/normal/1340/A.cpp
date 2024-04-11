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

int pos[N], a[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            pos[a[i]] = i;
        }
        int now = 1, r = n, ans = 1;
        while (now <= n) {
            int l = pos[now], ok = 1;
            for (int i = l, j = 0; i <= r; i++, j++) {
                if (a[i] != now + j) {
                    ok = 0;
                    break;
                }
            }
            now += (r - l + 1); r = l - 1;
            if (!ok) {
                ans = 0;
                break;
            }
        }
        if (ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}