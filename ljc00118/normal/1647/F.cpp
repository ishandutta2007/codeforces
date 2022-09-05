#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 5e5 + 5;

int a[N], v1[N], v2[N];
int n, ans, lim;

int calc() {
    int pos = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[pos]) {
            pos = i;
        }
    }
    int x = 0, y = 0;
    for (int i = n; i >= pos; i--) {
        if (a[i] > x) {
            x = a[i];
            continue;
        }
        if (a[i] > y) {
            y = a[i];
            continue;
        }
        return 0;
    }
    v1[0] = v2[0] = 0;
    lim = n + 1;
    for (int i = 1; i < pos; i++) {
        v1[i] = v1[i - 1];
        v2[i] = v2[i - 1];
        if (a[i] > v1[i]) {
            v1[i] = a[i];
            continue;
        }
        if (a[i] > v2[i]) {
            v2[i] = a[i];
            continue;
        }
        lim = i;
        break;
    }
    int ans = 0;
    if (pos != 1 && a[pos - 1] > y && pos - 1 < lim) ++ans;
    for (int i = pos - 2; i >= 1; i--) {
        if (i < lim) {
            int cando = 0;
            if (a[i + 1] < x && a[i + 1] > v1[i] + v2[i] - a[i] && a[i] > y) cando = 1;
            if (a[i + 1] > y && x > v1[i] + v2[i] - a[i] && a[i] > a[i + 1]) cando = 1;
            ans += cando;
        }
        if (a[i + 1] > x && a[i + 1] < y) break;
        if (a[i + 1] < x && a[i + 1] < y) {
            x = a[i + 1];
            continue;
        }
        if (a[i + 1] > x && a[i + 1] > y) {
            y = a[i + 1];
            continue;
        }
        if (a[i] > a[i + 1]) y = a[i + 1];
        else x = a[i + 1];
    }
    return ans;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    ans = calc();
    reverse(a + 1, a + n + 1);
    ans += calc();
    print(ans, '\n');
    return 0;
}