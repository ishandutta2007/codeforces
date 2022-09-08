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

const int N = 1005;

char c[N];
int ans[N];
int n, cnt;

int main() {
    scanf("%s", c + 1); n = strlen(c + 1);
    bool ok = 1, flag = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] == '(') {
            flag = 1;
        } else {
            if (flag) {
                ok = 0;
                break;
            }
        }
    }
    if (ok) {
        print(0, '\n');
        return 0;
    }
    print(1, '\n');
    int l = 1, r = n;
    while (l <= r) {
        while (l <= n && c[l] != '(') ++l;
        while (r >= 1 && c[r] != ')') --r;
        if (l > r) break;
        ans[l] = ans[r] = 1; ++l; --r; ++cnt;
    }
    print(cnt * 2, '\n');
    for (int i = 1; i <= n; i++) if (ans[i]) print(i, ' ');
    putchar('\n');
    return 0;
}