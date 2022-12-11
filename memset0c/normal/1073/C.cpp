#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 2e5 + 10;
int n, x, y, l, r, mid, c, now, ans;
int a[N], ax[N], ay[N], bx[N], by[N], dx[5], dy[5];

bool check(int i, int j) {
    int x1 = ax[i], x2 = bx[j], y1 = ay[i], y2 = by[j];
    int dis = abs(x2 - x1) + abs(y2 - y1);
    int tmp = j - i - 1;
    if ((dis & 1) != (tmp & 1) || tmp < 0) return false;
    return tmp >= dis;
}

void main() {
    read(n);
    dy[0] = 1, dy[1] = -1, dx[2] = -1, dx[3] = 1;
    for (int i = 1; i <= n; i++) {
        while (c = getchar(), !isupper(c));
        if (c == 'U') a[i] = 0;
        else if (c == 'D') a[i] = 1;
        else if (c == 'L') a[i] = 2;
        else a[i] = 3;
        // printf("a[%d] = %d\n", i, a[i]);
    }
    read(x), read(y);
    if (abs(x) + abs(y) > n) {
        puts("-1");
        return;
    }
    for (int i = 1; i <= n; i++) {
        ax[i] = ax[i - 1] + dx[a[i]];
        ay[i] = ay[i - 1] + dy[a[i]];
        // printf("a[%d] => %d %d : %d %d\n", i, ax[i], ay[i], dx[a[i]], dy[a[i]]);
    }
    bx[n + 1] = x, by[n + 1] = y;
    for (int i = n; i >= 1; i--) {
        bx[i] = bx[i + 1] - dx[a[i]];
        by[i] = by[i + 1] - dy[a[i]];
        // printf("b[%d] => %d %d\n", i, bx[i], by[i]);
    }
    if (ax[n] == x && ay[n] == y) {
        puts("0");
        return;
    }
    int ans = n + 1;
    for (int i = 0; i <= n; i++) {
        l = i + 1, r = n + 1;
        now = n + 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(i, mid)) {
                r = mid - 1;
                now = mid;
            } else {
                l = mid + 1;
            }
        }
        if (check(i, now)) {
            // printf("%d -> %d\n", i, now);
            ans = std::min(ans, now - i - 1);
        }
    }
    print(ans == n + 1 ? -1 : ans, '\n');
}

} signed main() { return ringo::main(), 0; }