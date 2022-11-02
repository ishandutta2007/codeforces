#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <ios>

using namespace std;

#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 500100;
const int mod = 1e9 + 7;

int n, h, w;
char s[2 * maxn];
int cx[maxn], cy[maxn];
int num[maxn], sze;

int dx(char c) {
    if (c == 'U') return -1;
    else if (c == 'D') return 1;
    return 0;
}

int dy(char c) {
    if (c == 'L') return -1;
    else if (c == 'R') return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> h >> w >> s;

    int lx = 0, rx = h, ly = 0, ry = w;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int add = ll(rx - lx) * (ry - ly) % mod;
        if (add == 0) {
            cout << ans << '\n';
            return 0;
        }
        ans = (ans + add) % mod;

        char c = s[i];
        lx = max(lx + dx(c), 0);
        rx = min(rx + dx(c), h);
        ly = max(ly + dy(c), 0);
        ry = min(ry + dy(c), w);
    }

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        cx[i] = x, cy[i] = y;
        int add = ll(rx - lx) * (ry - ly) % mod;
        if (add == 0) {
            cout << ans << '\n';
            return 0;
        }
        ans = (ans + add) % mod;

        char c = s[i];
        x += dx(c), y += dy(c);
        if (lx + dx(c) < 0 || rx + dx(c) > h || ly + dy(c) < 0 || ry + dy(c) > w) num[sze++] = i + 1;
        lx = max(lx + dx(c), 0);
        rx = min(rx + dx(c), h);
        ly = max(ly + dy(c), 0);
        ry = min(ry + dy(c), w);
    }
    cx[n] = x, cy[n] = y;

    if (sze == 0) {
        cout << "-1\n";
        return 0;
    }

    int last = 0;
    for (int i = 0; 1; i = (i + 1) % sze) {
        int k = num[i];
        int dif = k <= last ? k + n - last : k - last;
        int add = ll(rx - lx) * (ry - ly) % mod * dif % mod;
        if (add == 0) {
            cout << ans << '\n';
            return 0;
        }
        ans = (ans + add) % mod;

        int dx1 = cx[k] - cx[last] + (k <= last ? x : 0);
        int dy1 = cy[k] - cy[last] + (k <= last ? y : 0);
        lx = min(max(lx + dx1, 0), h);
        rx = min(max(rx + dx1, 0), h);
        ly = min(max(ly + dy1, 0), w);
        ry = min(max(ry + dy1, 0), w);
        last = k;
    }
}