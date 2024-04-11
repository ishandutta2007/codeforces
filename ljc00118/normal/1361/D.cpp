#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 5e5 + 5;

long double v[N], dis[N], sum, ans;
int x[N], y[N], dx[N], dy[N], id[N];
int n, k, tot;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

bool cmp(int a, int b) {
    if (dx[a] != dx[b]) return dx[a] < dx[b];
    if (dy[a] != dy[b]) return dy[a] < dy[b];
    // return abs(x[a]) < abs(x[b]);
    return dis[a] < dis[b];
}

int main() {
    read(n); read(k);
    for (int i = 1; i <= n; i++) {
        read(x[i]); read(y[i]);
        dis[i] = sqrt((long double)x[i] * x[i] + (long double)y[i] * y[i]);
        int d = gcd(abs(x[i]), abs(y[i]));
        if (d == 0) continue;
        dx[i] = x[i] / d; dy[i] = y[i] / d;
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    for (int l = 1, r; l <= n; l = r + 1) {
        r = l;
        while (r < n && dx[id[l]] == dx[id[r + 1]] && dy[id[l]] == dy[id[r + 1]]) ++r;
        // cout << dx[id[l]] << " " << dy[id[l]] << " " << l << " " << r << endl;
        int L = l, R = r; sum = 0;
        for (int cnt = 1; cnt <= min(r - l + 1, k); cnt++) {
            if (cnt <= k / 2) {
                // fprintf(stderr, "%.6lf %d\n", (double)dis[id[R]], cnt);
                v[++tot] = dis[id[R]] * (k - 2 * cnt + 1);
                --R;
            } else {
                v[++tot] = dis[id[L]] * (k - 1 - k / 2 - k / 2) - sum * 2;
                sum += dis[id[L]]; ++L;
            }
        }
    }
    sort(v + 1, v + tot + 1);
    for (int i = tot; i >= tot - k + 1; i--) ans += v[i];
    printf("%.10lf\n", (double)ans);
    return 0;
}