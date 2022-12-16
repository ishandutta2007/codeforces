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

const int maxn = 2e5 + 10;
int n, q, a[maxn], pr[20], cntp;
ll sum[20][maxn];
void work() {
    read(n, q);
    for (int i = 1; i <= n; ++i) read(a[i]);
    cntp = 0;
    int t = n;
    for (int i = 2; i * i <= t; ++i) if (t % i == 0) {
        pr[++cntp] = n / i;
        while (t % i == 0) t /= i;
    }
    if (t > 1) pr[++cntp] = n / t;
    multiset <ll> s;
    for (int i = 1; i <= cntp; ++i) {
        for (int j = 0; j < pr[i]; ++j) sum[i][j] = 0;
        for (int j = 1; j <= n; ++j) sum[i][j % pr[i]] += a[j];
        for (int j = 0; j < pr[i]; ++j) s.insert(sum[i][j] * pr[i]);
    }
    write(*--s.end(), '\n');
    while (q--) {
        int p, x; read(p, x);
        for (int i = 1; i <= cntp; ++i) {
            s.erase(s.find(sum[i][p % pr[i]] * pr[i]));
            sum[i][p % pr[i]] += x - a[p];
            s.insert(sum[i][p % pr[i]] * pr[i]);
        }
        a[p] = x;
        write(*--s.end(), '\n');
    }
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}