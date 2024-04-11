#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define answer(ans) {cout << (ans) << endl; return;}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int x = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > a[i + 1] && (a[i + 1] - a[n - 1] > a[i + 1] || i == n - 2)) answer(-1)
        if (a[i] > a[i + 1]) {
            x = i + 1;
            break;
        }
    }
    cout << x << '\n';
    for (int i = x - 1; i >= 0; --i) cout << i + 1 << ' ' << x + 1 << ' ' << n << '\n';
}