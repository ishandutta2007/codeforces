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

int lim[N], st[N], ans[N];
int n, top, cnt;

int main() {
    read(n);
    for (int i = 1; i <= n * 2; i++) {
        char c = getchar();
        while (c != '+' && c != '-') c = getchar();
        if (c == '+') {
            ++cnt;
            st[++top] = cnt;
        } else {
            int id; read(id);
            if (!top) {
                printf("NO\n");
                return 0;
            }
            if (lim[top] && id < lim[top]) {
                printf("NO\n");
                return 0;
            }
            ans[st[top]] = id;
            lim[top] = 0;
            --top;
            lim[top] = max(lim[top], id);
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
    return 0;
}