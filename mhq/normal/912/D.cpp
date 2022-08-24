#include <bits/stdc++.h>
using namespace std;
int n, m, r, k;
priority_queue < pair < long long, pair < int, int > > > q;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> r >> k;
    int c1 = min(r, n - r + 1);
    int c2 = min(r, m - r + 1);
    for (int i = c1; i >= max(c1 - (int)1e3, 1); i--) {
        for (int j = c2; j >= max(c2 - (int)1e3, 1); j--) {
            q.push(make_pair(1LL * i * j, make_pair(i ,j)));
        }
    }
    long long ans = 0;
    while (k > 0) {
        auto s = q.top();
        q.pop();
        int x = s.second.first;
        int y = s.second.second;
        int ansx = 0;
        int ansy = 0;
        if (r == x) {
            ansx = n + 2 - 2 * x;
        }
        else if (n - r + 1 == x) {
            ansx = n + 2 - 2 * x;
        }
        else {
            ansx = 2;
            if (2 * x == (n + 1)) {
                ansx = 1;
            }
        }
        if (r == y) {
            ansy = m + 2 - 2 * y;
        }
        else if (m - r + 1 == y) {
            ansy = m + 2 - 2 * y;
        }
        else {
            ansy = 2;
            if (2 * y == (m + 1)) {
                ansy = 1;
            }
        }
        if (k >= 1LL * ansx * ansy) {
            k -= ansx * ansy;
            ans = ans + ansx * ansy * s.first;
        }
        else {
            ans = ans + k * s.first;
            k = 0;
        }
    }
    cout << fixed << setprecision(15) << (1.0 * ans) / (1LL * (n - r + 1) * (m - r + 1));
    return 0;
}