#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int te, n, u;
bool chk[N];

void solve() {
    cin >> n;
    fill(chk, chk + n, false); // f
    for (int i = 0; i < n; i++) {
        cin >> u; u %= n;
        chk[(i + u + n) % n] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!chk[i]) {
            return void(cout << "NO\n");
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    while (te--) {
        solve();
    }
}