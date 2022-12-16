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

vi ans;
int n;
void f(int i, int j) {
    int m = (j + n - i) % n;
    int l = 0, r = m;
    while (l < r) {
        for (int k = r - 1; k >= l; --k) ans.push_back((i + k) % n);
        for (int k = l + 1; k < r; ++k) ans.push_back((i + k) % n);
        ++l, --r;
    }
    for (int k = 0; k < m / 2; ++k) ans.push_back((i + k) % n);
}

int main() {
    read(n);
    if (n & 1) f(0, n - 1), f((n + 1) >> 1, (n - 3) >> 1), f(0, n - 1);
    else f(0, n - 1), f(n >> 1, (n - 1) >> 1), f(0, n - 1);
    write(ans.size(), '\n');
    for (int x : ans) write(x, ' ');
    write('\n');
	return 0;
}