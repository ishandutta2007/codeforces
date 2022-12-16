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
int n, m, a[maxn];
void work() {
    read(n, m);
    for (int i = 1; i <= m; ++i) read(a[i]);
    sort(a + 1, a + m + 1);
    vi b;
    for (int i = 1; i < m; ++i) b.push_back(a[i + 1] - a[i] - 1);
    b.push_back(n - a[m] + a[1] - 1);
    sort(b.begin(), b.end(), greater <int> ());
    int ans = 0, tim = 0;
    for (int len : b)
        ans += max(0, len - tim == 1 ? 1 : len - tim - 1), tim += 4;
    write(n - ans, '\n');
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}