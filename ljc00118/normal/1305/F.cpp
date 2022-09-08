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

const int N = 2e5 + 5, INF = 0x7fffffff;

map <ll, int> wxw, wxw2;
int used[N];
ll a[N];
int n, ans;

inline int brand() { return (rand() << 15) ^ rand(); }

int calc(ll x) {
    if (wxw.count(x)) return ans;
    wxw[x] = 1; ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < x) sum += x - a[i];
        else sum += min(a[i] % x, x - a[i] % x);
        if (sum >= INF) return INF;
    }
    return sum;
}

void solve(ll x) {
    if (!x) return;
    while (x % 2 == 0) x >>= 1;
    if (wxw2.count(x)) return;
    wxw2[x] = 1;
    for (int i = 3; 1ll * i * i <= x; i += 2) {
        if (x % i == 0) {
            ans = min(ans, calc(i));
            while (x % i == 0) x /= i;
        }
    }
    if (x != 1) ans = min(ans, calc(x));
}

int main() {
    srand(time(0));
    int start = clock();
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), ans += (a[i] & 1);
    while ((clock() - start) <= 2 * CLOCKS_PER_SEC) {
        int pos = brand() % n + 1;
        if (used[pos]) continue;
        used[pos] = 1;
        solve(a[pos] - 1); solve(a[pos]); solve(a[pos] + 1);
    }
    print(ans, '\n');
    return 0;
}