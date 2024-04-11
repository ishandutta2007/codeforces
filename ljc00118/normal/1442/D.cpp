#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 3005;

vector <int> t[N];
ll sum[N];
int n, k;

vector <ll> solve(int l, int r) {
    if (l == r) {
        int len = min((int)t[l].size() - 1, k);
        vector <ll> ans(k + 1, 0);
        for (int i = 1; i <= len; i++) ans[i] = ans[i - 1] + t[l][i];
        return ans;
    }
    int mid = (l + r) >> 1;
    vector <ll> dpl = solve(l, mid);
    vector <ll> dpr = solve(mid + 1, r);
    vector <ll> ans(k + 1, 0);
    for (int i = mid + 1; i <= r; i++) {
        int big = min((int)t[i].size() - 1, k);
        ll val = sum[i];
        for (int j = k; j >= big; j--) dpl[j] = max(dpl[j], dpl[j - big] + val);
    }
    for (int i = l; i <= mid; i++) {
        int big = min((int)t[i].size() - 1, k);
        ll val = sum[i];
        for (int j = k; j >= big; j--) dpr[j] = max(dpr[j], dpr[j - big] + val);
    }
    for (int i = 0; i <= k; i++) ans[i] = max(dpl[i], dpr[i]);
    return ans;
}

int main() {
    read(n); read(k);
    for (int i = 1; i <= n; i++) {
        int m; read(m);
        t[i].resize(m + 1);
        for (int j = 1; j <= m; j++) {
            read(t[i][j]);
            if (j <= k) sum[i] += t[i][j];
        }
    }
    vector <ll> ans = solve(1, n);
    print(ans[k], '\n');
    return 0;
}