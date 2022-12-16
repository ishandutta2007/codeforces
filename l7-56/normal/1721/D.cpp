#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (int i = 0; s[i]; ++i) putchar(s[i]); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn];
vector <pii> now, nxt;
void work() {
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]);
    for (int i = 1; i <= n; ++i) read(b[i]);
    now.resize(0);
    now.emplace_back(1, n);
    int ans = 0;
    for (int bit = 29; bit >= 0; --bit) {
        auto qsort = [&] (int l, int r, int a[maxn]) {
            int i = l, j = r;
            while (i < j) {
                while (i < j && !((a[i] >> bit) & 1)) ++i;
                while (i < j && ((a[j] >> bit) & 1)) --j;
                swap(a[i], a[j]);
            }
        };
        int flg = 1;
        for (pii p : now) {
            int l = p.fir, r = p.sec;
            qsort(l, r, a), qsort(l, r, b);
            int i = l - 1, j = l - 1;
            while (i < r && !((a[i + 1] >> bit) & 1)) ++i;
            while (j < r && !((b[j + 1] >> bit) & 1)) ++j;
            if (i - l + 1 != r - j) { flg = 0; break; }
            reverse(b + l, b + r + 1);
            if (l <= i) nxt.emplace_back(l, i);
            if (i < r) nxt.emplace_back(i + 1, r);
        }
        if (flg) now.swap(nxt), ans |= (1 << bit);
        nxt.resize(0);
    }
    write(ans, '\n');
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}