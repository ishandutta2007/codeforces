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
ll n, m, k, a[maxn], b[maxn];
int check() {
    for (int i = 1; i <= k; ++i) {
        b[i] = a[i] / n;
        if (b[i] < 2) b[i] = 0;
    }
    sort(b + 1, b + k + 1, greater <int> ());
    ll cnt = m / 2, sum = 0;
    for (int i = 1; i <= cnt && i <= k; ++i) sum += b[i];
    return sum >= m;
}

void work() {
    read(n, m, k);
    for (int i = 1; i <= k; ++i) read(a[i]);
    if (check()) return write("Yes\n");
    swap(n, m);
    if (check()) return write("Yes\n");
    write("No\n");
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}