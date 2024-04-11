// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
    x = 0; register char ch; register bool fl = 0;
    while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
    while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
    if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
    while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
    static int buf[40];
    if (x == 0) { putc('0'); putc(c); return; }
    if (x < 0) putc('-'), x = -x;
    for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
    while (buf[0]) putc((char) buf[buf[0]--]);
    putc(c);
}

const int maxn = 100010;
const long double eps = 1e-7;

int n, cnt = 1000;
int x[maxn], y[maxn];

bool flag1, flag2;

long double l, r, mid, ans, tmp;
long double dis, min_rx, max_lx;
long double lx[maxn], rx[maxn];

bool check(long double r) {
    for (int i = 1; i <= n; i++) {
        tmp = (2 * r - y[i]) * y[i];
//		tmp = r * r - (r - y[i]) * (r - y[i]);
        if (tmp < 0)
            return false;
        dis = sqrt(tmp);
        lx[i] = x[i] - dis;
        rx[i] = x[i] + dis;
//		printf(">>> %.8Lf\n", dis);
    }
//	for (int i = 1; i <= n; i++)
//		printf("%.8Lf %.8Lf\n", lx[i], rx[i]);
    min_rx = rx[1];
    for (int i = 2; i <= n; i++)
        min_rx = std::min(min_rx, rx[i]);
    max_lx = lx[1];
    for (int i = 2; i <= n; i++)
        max_lx = std::max(max_lx, lx[i]);
    if (max_lx > min_rx)
        return false;
//	printf("%.8Lf : %.8Lf %.8Lf\n", r, min_rx, max_lx); 
    return true;
}

int main() {
//	freopen("1.txt", "r", stdin);
    read(n);
    for (int i = 1; i <= n; i++) {
        read(x[i]);
        read(y[i]);
    }
    for (int i = 1; i <= n; i++)
        if (y[i] < 0) flag1 = 1;
        else if (y[i] > 0) flag2 = 1;
    if (flag1 && flag2) {
        print(-1, '\n');
        return 0;
    }
    if (flag1) {
        for (int i = 1; i <= n; i++)
            y[i] = -y[i];
    }
    
    l = 0, r = 1000000000000001;
    while (r - l >= eps && --cnt) {
        mid = (l + r) * 0.5;
//		printf("=== %.8Lf %.8Lf %.8Lf %.8Lf %.8Lf\n", l, mid, r, l / 2, r / 2);
        if (check(mid)) {
//			printf(">> true\n");
            ans = mid;
            r = mid;
        } else {
//			printf(">> false\n");
            l = mid;
        }
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(8) << ans;
    std::cout << std::endl;
    //ds/fsffdfsdf
    return 0;
}