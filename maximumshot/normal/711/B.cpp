#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n;
    cin >> n;

    vec< vec< ll > > a(n, vec< ll >(n));
    int i0, j0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                i0 = i;
                j0 = j;
            }
        }
    }

    ll last = -1;

    for (int i = 0; i < n; i++) {
        if (i == i0) continue;
        ll sum = 0;
        for (int j = 0; j < n; j++) sum += a[i][j];
        if (last != -1 && last != sum) {
            cout << -1 << '\n';
            return true;
        }
        last = sum;
    }

    for (int j = 0; j < n; j++) {
        if (j == j0) continue;
        ll sum = 0;
        for (int i = 0; i < n; i++) sum += a[i][j];
        if (last != -1 && last != sum) {
            cout << -1 << '\n';
            return true;
        }
        last = sum;
    }

    if (i0 != j0) {
        ll sum = 0;
        for (int i = 0; i < n; i++) sum += a[i][i];
        if (last != -1 && last != sum) {
            cout << -1 << '\n';
            return true;
        }
        last = sum;
    }

    if (i0 + j0 != n - 1) {
        ll sum = 0;
        for (int i = 0; i < n; i++) sum += a[i][n - 1 - i];
        if (last != -1 && last != sum) {
            cout << -1 << '\n';
            return true;
        }
        last = sum;
    }

    if (n == 1) {
        cout << "1\n";
        return true;
    }

    ll str = 0, col = 0;

    for (int j = 0; j < n; j++) str += a[i0][j];
    for (int i = 0; i < n; i++) col += a[i][j0];

    ll x = last - str;

    if (x <= 0 || col + x != last) {
        cout << -1 << '\n';
        return true;
    }

    a[i0][j0] = x;

    {
        ll sum = 0;
        for (int i = 0; i < n; i++) sum += a[i][i];
        if (last != -1 && last != sum) {
            cout << -1 << '\n';
            return true;
        }
        last = sum;
    }

    {
        ll sum = 0;
        for(int i = 0;i < n;i++) sum += a[i][n - 1 - i];
        if(last != -1 && last != sum) {
            cout << -1 << '\n';
            return true;
        }
        last = sum;
    }

    cout << x << '\n';

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}