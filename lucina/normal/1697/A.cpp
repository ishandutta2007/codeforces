#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[128];

void solve() {
    cin >> n >> m;
    m = -m;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        m += a[i];
    }
    cout << max(0, m) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ;T-- ; ) {
        solve();
    }
}