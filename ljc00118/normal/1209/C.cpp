#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
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

const int N = 2e5 + 5;

char c[N];
int ans[N], a[N];
int T, n;

int main() {
    read(T);
    while(T--) {
        read(n); scanf("%s", c + 1);
        for(register int i = 1; i <= n; i++) ans[i] = 2, a[i] = c[i] - '0';
        bool ok = 1; int maxn = a[1], fir = -1;
        for(register int i = 2; i <= n; i++) {
            if(a[i] < maxn) {
                if(a[i] < fir) {
                    ok = 0;
                    break;
                }
                ans[i] = 1; fir = a[i];
            } else maxn = a[i];
        }
        if(!ok) {
            printf("-\n");
            continue;
        }
        if(fir == -1) {
            for(register int i = 1; i <= n; i++) {
                putchar(ans[i] + '0');
            }
            putchar('\n');
            continue;
        } 
        for(register int i = 1; i <= n; i++) {
            if(ans[i] == 2 && fir > a[i]) {
                ans[i] = 1;
            }
        }
        fir = -1;
        for(register int i = 1; i <= n; i++) {
            if(ans[i] == 1) {
                if(a[i] < fir) {
                    ok = 0;
                    break;
                }
                fir = a[i];
            }
        }
        if(!ok) {
            printf("-\n");
            continue;
        }
        for(register int i = 1; i <= n; i++) {
            putchar(ans[i] + '0');
        }
        putchar('\n');
    }
    return 0;
}