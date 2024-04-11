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

const int N = 1e6 + 5;

char c[N];
int n, cnt;

int main() {
    read(n); scanf("%s", c + 1);
    for (int i = 1; i <= n; i++) if (c[i] == 'P') ++cnt;
    if (cnt == 1) {
        int l = 0, wl = 0, r = 0, wr = 0, pos;
        for (int i = 1; i <= n; i++) if (c[i] == 'P') pos = i;
        wl = wr = pos;
        for (int i = pos; i >= 1; i--) if (c[i] == '*') ++l, wl = i;
        for (int i = pos; i <= n; i++) if (c[i] == '*') ++r, wr = i;
        if (l < r) {
            printf("%d %d\n", r, wr - pos);
        } else if (l > r) {
            printf("%d %d\n", l, pos - wl);
        } else {
            printf("%d %d\n", l, min(wr - pos, pos - wl));
        }
        return 0;
    }
    int l = 1, r = n - 1, ans = n;
    while (l <= r) {
        int mid = (l + r) >> 1, ans1 = 0, ans2 = -10000000, lasD = -10000000, lasB = 0, ok1 = 1, ok2 = 1;
        // ans1 :  D ,  B 
        // ans2 :  D ,  D 
        for (int i = 1; i <= n; i++) {
            if (c[i] == '*') {
                if (ok1 && !ans1 && i - lasD > mid) ans1 = i;
                if (ok2 && !lasB && i - ans2 > mid) lasB = i;
            }
            if (c[i] == 'P') {
                int _ans1, _ans2, _ok1 = 0, _ok2 = 0;
                if (ok1) {
                    _ok1 = 1;
                    _ans1 = ans1;
                    if (!ans1 || i - ans1 <= mid) {
                        _ok2 = 1;
                        _ans2 = lasD;
                    }
                }
                if (ok2) {
                    if (_ok1 == 1) {
                        if (!lasB) _ans1 = 0;
                        else if (_ans1) _ans1 = max(_ans1, lasB);
                    } else _ok1 = 1, _ans1 = lasB;
                    if (!lasB || i - lasB <= mid) {
                        if (!_ok2) {
                            _ok2 = 1;
                            _ans2 = ans2;
                        }
                    }
                }
                ans1 = _ans1; ans2 = _ans2; ok1 = _ok1; ok2 = _ok2;
                lasD = i; lasB = 0;
            }
        }
        if ((ok1 && !ans1) || (ok2 && !lasB)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) if (c[i] == '*') ++cnt;
    printf("%d %d\n", cnt, ans);
    return 0;
}