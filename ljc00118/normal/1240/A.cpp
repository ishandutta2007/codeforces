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

ll k;
int p[N];
int T, n, a, x, b, y;

inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

bool check(int mid) {
    int all = mid / (1ll * a * b / gcd(a, b)), A = mid / a - all, B = mid / b - all;
    // cout << mid << " " << all << " " << A << " " << B << endl;
    ll sum = 0;
    for(register int i = 1; i <= all; i++) sum += p[i] / 100 * (x + y);
    for(register int i = all + 1; i <= all + A; i++) sum += p[i] / 100 * x;
    for(register int i = all + A + 1; i <= all + A + B; i++) sum += p[i] / 100 * y;
    return sum >= k;
}

int main() {
    read(T);
    while(T--) {
        read(n);
        for(register int i = 1; i <= n; i++) read(p[i]);
        sort(p + 1, p + n + 1); reverse(p + 1, p + n + 1);
        read(x); read(a); read(y); read(b); read(k);
        if(x < y) swap(x, y), swap(a, b);
        int l = 1, r = n, ans = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(check(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        print(ans, '\n');
    }
    return 0;
}