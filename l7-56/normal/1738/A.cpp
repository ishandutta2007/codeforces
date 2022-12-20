#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef pair <int, int> pii;
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
int n;
pii p[maxn];
void work() {
    vector <ll> a[2];
    read(n);
    for (int i = 1; i <= n; ++i) read(p[i].fir);
    for (int i = 1; i <= n; ++i) read(p[i].sec), a[p[i].fir].push_back(p[i].sec);
    sort(begin(a[0]), end(a[0]), greater <ll> ());
    sort(begin(a[1]), end(a[1]), greater <ll> ());
    if (a[0].size() > a[1].size()) a[0].swap(a[1]);
    if (a[0].size() < a[1].size()) {
        ll ans = 0;
        for (ll x : a[0]) ans += x * 2;
        for (int i = 0; i < (int) a[0].size(); ++i) ans += a[1][i] * 2;
        for (int i = a[0].size(); i < (int) a[1].size(); ++i) ans += a[1][i];
        write(ans, '\n');
        return;
    }
    if (a[0].size() == a[1].size()) {
        ll ans = 0;
        for (int x : a[0]) ans += x;
        for (int x : a[1]) ans += x;
        ans = ans * 2 - min(a[0].back(), a[1].back());
        write(ans, '\n');
    }
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}