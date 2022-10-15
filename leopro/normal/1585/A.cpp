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
#define DIE {cout << "-1\n"; return;}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i]) { if (i && a[i - 1]) k += 5; else k += 1; } else { if (i && !a[i - 1]) DIE; }
    }
    cout << k + 1 << '\n';
}