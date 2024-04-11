#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int64_t n;
int m;
array <int, 2> a[nax];
int64_t sum_a[nax];
int64_t sum_b[nax];

int64_t ex_gcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

bool sw;
int64_t last_profit = 0;

int64_t solve() {
        int64_t x, y;
        cin >> x >> y;
        if (sw) swap(x, y);
        int64_t a, b;
        int64_t g = ex_gcd(x, y, a, b);
        if (n % g) {
            return -1;
        }
        int64_t shift_x = abs(y / g);
        int64_t shift_y = abs(x / g);
        int64_t d = n / g;
        a *= d, b *= d;
        if (b < 0) {
            int64_t need = (abs(b) + shift_y - 1) / shift_y;
            b += shift_y * need;
            a = (n - y * b) / x;
        }
        if (b > 0) {
            int64_t need = b / shift_y;
            b -= shift_y * need;
            a = (n - y * b) / x;
        }
        if (a < 0) return -1;
        int64_t cur_blue = b * y;
        int64_t real_shift = shift_y * y;
        int64_t to = cur_blue + max(int64_t(0), (last_profit - cur_blue) / real_shift) * real_shift;
        int64_t ans = sum_a[n] - sum_a[to] + sum_b[to];
        to = cur_blue + max(int64_t(0), (last_profit - cur_blue + real_shift - 1) / real_shift) * real_shift;
        if (to <= n) ans = max(ans, sum_a[n] - sum_a[to] + sum_b[to]);
        return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    int64_t sx = 0, sy = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i][0] >> a[i][1];
        sx += a[i][0], sy += a[i][1];
    }
    sw = sx > sy;
    if (sw) for (int i = 1 ; i <= n ; ++ i) swap(a[i][0], a[i][1]);

    sort(a + 1, a + 1 + n, [](const array <int, 2> &x, const array <int, 2> & y) {
            return x[1] - x[0] > y[1] - y[0];
    });
    for (int i = 1 ; i <= n ; ++ i) {
        sum_a[i] = sum_a[i - 1] + a[i][0];
        sum_b[i] = sum_b[i - 1] + a[i][1];
        if (a[i][1] - a[i][0] >= 0) last_profit = i;
    }
    int m;
    cin >> m;

    while (m --) {
        cout << solve() << '\n';
    }
}