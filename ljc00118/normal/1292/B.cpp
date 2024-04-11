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

const int N = 100;

ll x[N], y[N], ax, ay, bx, by, sx, sy, t;
int len, ans;

ll dis(ll x, ll y, ll _x, ll _y) { return abs(x - _x) + abs(y - _y); }

int main() {
    read(x[0]); read(y[0]); read(ax); read(ay); read(bx); read(by); read(sx); read(sy); read(t);
    while (x[len] - sx <= t && y[len] - sy <= t) {
        ++len;
        x[len] = x[len - 1] * ax + bx;
        y[len] = y[len - 1] * ay + by;
    }
    --len;
    for (int l = 0; l <= len; l++) {
        for (int r = l; r <= len; r++) {
            ll sum = min(dis(sx, sy, x[l], y[l]), dis(sx, sy, x[r], y[r]));
            for (int i = l + 1; i <= r; i++) {
                if (sum > t) break;
                sum += dis(x[i - 1], y[i - 1], x[i], y[i]);
            }
            if (sum <= t) ans = max(ans, r - l + 1);
            // cout << sum << " " << r - l + 1 << endl;
        }
    }
    print(ans, '\n');
    return 0;
}