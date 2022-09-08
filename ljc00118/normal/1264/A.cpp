#include <bits/stdc++.h>
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 4e5 + 5;

int a[N], p[N];
int T, n, g, s, b, maxn;

int main() {
    read(T);
    while(T--) {
        g = s = b = maxn = 0;
        read(n);
        for(register int i = 1; i <= n; i++) read(a[i]);
        sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);
        p[n] = n;
        for(register int i = n - 1; i >= 1; i--) {
            if(a[i] != a[i + 1]) {
                p[i] = i;
                if(i <= n / 2) maxn = max(maxn, i);
            } else p[i] = p[i + 1];
        }
        if(!maxn) {
            printf("0 0 0\n");
            continue;
        }
        bool ok = 0;
        for(register int i = 1; i <= n / 2; i++) {
            if(a[i] != a[i + 1]) {
                int pos = p[i * 2 + 1];
                if(i < maxn - pos) {
                    ok = 1;
                    printf("%d %d %d\n", i, pos - i, maxn - pos);
                    break;
                }
            }
        }
        if(!ok) printf("0 0 0\n");
    }
    return 0;
}