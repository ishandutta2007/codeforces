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

int a[N], c[N], ta[N], tc[N], id[N];
int n, ans, pos; ll sumc;

bool cmp(int i, int j) { return a[i] < a[j]; }

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]); read(c[i]); sumc += c[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        ta[i] = a[id[i]];
        tc[i] = c[id[i]];
    }
    for (int i = 1; i <= n; i++) {
        a[i] = ta[i];
        c[i] = tc[i];
    }
    for (int i = 1; i <= n; i++) {
        if (id[i] == 1) {
            pos = i;
        }
    }
    int sum = 0, nowr = a[1] + c[1];
    for (int i = 2; i <= n; i++) {
        if (i == pos && i != n) continue;
        if (nowr < a[i]) sum += a[i] - nowr;
        nowr = max(nowr, a[i] + c[i]);
    }
    ans = sum; sum = 0; nowr = a[pos] + c[pos];
    for (int i = pos + 1; i <= n; i++) {
        if (nowr < a[i]) sum += a[i] - nowr;
        nowr = max(nowr, a[i] + c[i]);
    }
    nowr = a[1] + c[1];
    for (int i = 1; i <= pos; i++) {
        if (nowr < a[i]) sum += a[i] - nowr;
        nowr = max(nowr, a[i] + c[i]);
    }
    ans = min(ans, sum);
    print(ans + sumc, '\n');
    return 0;
}