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

const int N = 2005;

int a[N], wxw[N], b[N];
int n, ans;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    for(register int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    for(register int i = n; i >= 1; i--) {
        if(wxw[a[i]]) {
            ans = max(ans, n - i);
            break;
        }
        ++wxw[a[i]];
    }
    if(ans == 0) { print(0, '\n'); return 0; }
    memset(wxw, 0, sizeof(wxw));
    for(register int i = 1; i <= n; i++) {
        ++wxw[a[i]];
        if(wxw[a[i]] == 2) break;
        for(register int j = n; j >= i; j--) {
            if(!wxw[a[j]]) ++wxw[a[j]];
            else {
                for(register int k = j + 1; k <= n; k++) --wxw[a[k]];
                ans = max(ans, n - j + i);
                break;
            }
        }
    }
    print(n - ans, '\n');
    return 0;
}