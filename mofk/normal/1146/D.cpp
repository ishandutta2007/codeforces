#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, int> ii;
int n, a, b;
long long ans;
int d[200005];

long long range_sum(int f, int x) {
    int c = x / f + 1;
    return 1LL * (n + 1) * c - 1LL * f * c * (c - 1) / 2;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b;
    int m = n;
    memset(d, -1, sizeof d);
    d[0] = 0;
    queue <int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u >= b && !~d[u - b]) {
            d[u - b] = max(u - b, d[u]);
            q.push(u - b);
        }
        if (u < b && !~d[u + a]) {
            d[u + a] = max(u + a, d[u]);
            q.push(u + a);
        }
    }
    for (int i = 0; i < a + b; ++i)
        if (~d[i]) ans += max(0, m - d[i] + 1);
    int f = __gcd(a, b);
    if (a + b <= m) {
        ans += range_sum(f, m);
        ans -= range_sum(f, a + b - 1);
    }
    cout << ans << endl;
    return 0;
}