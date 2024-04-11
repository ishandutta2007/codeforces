#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
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

int a[100005], b[100005];
int n, m, k, ans;

int main() {
    read(n); read(m); read(k);
    for(register int i = 1; i <= n; i++) read(a[i]);
    ans = a[n] - a[1] + 1;
    for(register int i = 1; i < n; i++) b[i] = a[i + 1] - a[i] - 1;
    sort(b + 1, b + n);
    for(register int i = n - 1; i >= 1 && i >= n - k + 1; i--) ans -= b[i];
    cout << ans << endl;
    return 0;
} //