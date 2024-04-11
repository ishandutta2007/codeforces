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

priority_queue < pair <ll, int> > Q;
int a[N], cnt[N];
int n, k; ll sum;

inline ll getv(int a, int b) {
    if (a < b) return a;
    int cnt1 = a % b, cnt2 = b - cnt1;
    // cout << a << " " << b << " " << 1ll * cnt1 * (a / b + 1) * (a / b + 1) + 1ll * cnt2 * (a / b) * (a / b) << endl;
    return 1ll * cnt1 * (a / b + 1) * (a / b + 1) + 1ll * cnt2 * (a / b) * (a / b);
}

int main() {
    read(n); read(k); k -= n;
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        Q.push(make_pair(getv(a[i], 1) - getv(a[i], 2), i));
        sum += 1ll * a[i] * a[i]; cnt[i] = 1;
    }
    for (int i = 1; i <= k; i++) {
        pair <ll, int> u = Q.top(); Q.pop();
        sum -= u.first; ++cnt[u.second];
        Q.push(make_pair(getv(a[u.second], cnt[u.second]) - getv(a[u.second], cnt[u.second] + 1), u.second));
    }
    print(sum, '\n');
    return 0;
}