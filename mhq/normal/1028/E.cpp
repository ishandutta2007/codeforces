#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000 * 1000 * 1000 + 7;
set < int > buy, add, hz;
int n;
const int maxN = 4 * (int)1e5;
int b[2 * maxN];
ll a[2 * maxN];
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int zeroes = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[n + i] = b[i];
        if (b[i] == 0) zeroes++;
    }
    if (zeroes == n) {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++) {
            cout << 1 << " ";
        }
        return 0;
    }
    bool ok = false;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] != b[i + 1]) ok = true;
        mx = max(mx, b[i]);
    }
    if (ok == false) {
        cout << "NO";
        return 0;
    }
    int ind = -1;
    for (int i = 1; i <= n; i++) {
        if (b[i] != mx && b[i + 1] == mx) {
            ind = i + 1;
            if (ind > n) ind -= n;
            break;
        }
    }
    if (zeroes == (n - 1)) {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++) {
            if (i != ind) cout << 2 * mx << " ";
            else cout << mx << " ";
        }
        return 0;
    }
    assert(ind != -1);
    ll sum = 0;
    ll big = (ll)1e17;
    int x = ind - 1;
    if (x == 0) x = n;
    big = ((big / b[ind]) * b[ind]) + b[ind];
    for (int i = 1; i <= n; i++) sum += b[i];
    for (int i = 1; i <= n; i++) {
        int t = ind + i;
        if (t > n) t -= n;
        if (t != ind) a[t] = sum + big;
        else a[t] = sum;
        sum -= b[t];
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        int x = i;
        int y = (i + 1);
        if (y > n) y -= n;
        assert(a[x] <= (ll)1e18);
        if ((a[x] % (a[y])) != b[i]) {
            //cout << a[x] % (a[y]) << " " << b[i] << " " << a[x] << " " << a[y] << endl;
            assert(0);
        }
        cout << a[i] << " ";
    }
    return 0;
}