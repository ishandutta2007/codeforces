#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int n, a, b;

void solve() {
    int cnt = n - 2;
    if (abs(a - b) > 1 || a + b > cnt) {
        puts("-1");
        return;
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        v.PB(i);
    }
    if (a == b) {
        int ca = n;
        int cb = n - (a + 1);
        for (int i = 0; i < (a + 1); ++i) {
            cout << ca-- << ' ' << cb-- << ' ';
        }
        for (int i = cb; i >= 1; --i) {
            cout << i << ' ';
        }
        cout << "\n";
        return;
    }
    if (a > b) {
        int ca = n;
        int cb = n - a;
        for (int i = 0; i < a; ++i) {
            cout << cb-- << ' ' << ca-- << ' ';
        }
        for (int i = cb; i >= 1; --i) {
            cout << i << ' ';
        }
        cout << "\n";
        return;
    }
    if (b > a) {
        int ca = 2 * b;
        int cb = b;
        for (int i = 0; i < b; ++i) {
            cout << ca-- << ' ' << cb--  << ' ';
        }
        for (int i = 2 * b + 1; i <= n; ++i) {
            cout << i << ' ';
        }
        cout << "\n";
        return;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ///ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        solve();
    }

    return 0;
}