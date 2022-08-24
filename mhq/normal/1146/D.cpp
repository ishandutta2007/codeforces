#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e6 + 100;
ll m;
int a, b;
bool vis[maxN + 20];
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return (a + b);
}
ll prvans = 1;
void dfs(int i, int lim) {
    if (vis[i]) return ;
    vis[i] = true;
    prvans++;
    if (i + a <= lim) dfs(i + a, lim);
    if (i >= b) dfs(i - b, lim);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> m >> a >> b;
    ll sum = 1;
    vis[0] = true;
    for (int i = 1; i <= min((int)m, maxN); i++) {
        if (i >= a && vis[i - a]) {
            dfs(i, i);
        }
        sum += prvans;
    }
    if (m <= maxN) {
        cout << sum << endl;
        return 0;
    }
    int d = gcd(a, b);
    int cur = maxN + 1;
    while (m % d != 0) {
        if (m < cur) break;
        sum += (m / d) + 1;
        m--;
    }
    while (cur % d != 0) {
        if (cur > m) break;
        sum += (cur / d) + 1;
        cur++;
    }
    if (m >= cur) {
        sum += (m / d) + 1;
        m--;
    }
    if (m >= cur) {
        ll cnt = (m / d) - (cur / d) + 1;
        ll F = (cur / d) + (m / d) + 2;
        ll f1 = (cnt * F) / 2;
        sum += d * ((cnt * F) / 2);
    }
    cout << sum;
    return 0;
}