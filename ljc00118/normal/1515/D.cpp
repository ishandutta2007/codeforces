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

const int N = 2e5 + 5;

int a[N], cnt[N];
int T, n, l, r;

int main() {
    read(T);
    while (T--) {
        read(n); read(l); read(r);
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            if (i <= l) --cnt[a[i]];
            else ++cnt[a[i]];
        }
        int _cnt = abs(r - l) / 2, cnt2 = 0, cnt3 = 0;
        for (int i = 1; i <= n; i++) {
            cnt2 += abs(cnt[i]);
            if (l < r && cnt[i] > 0) cnt3 += cnt[i] / 2;
            if (l > r && cnt[i] < 0) cnt3 += (-cnt[i]) / 2;
        }
        print(_cnt + cnt2 / 2 - min(_cnt, cnt3), '\n');
    }
    return 0;
}