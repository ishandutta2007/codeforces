#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
void solve() {
    cin >> n;
    int m = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        m = max(m, a[i]);
    }
    set <pair <int, int>> s;
    for (int i = 1 ; i <= n ; ++ i) {
        s.emplace(i, a[i]);
    }
    int k =0;
    while (true) {
        if (s.rbegin()->second == m) break;
        int v = s.rbegin()->second;
        k ++;
        while (!s.empty() && s.rbegin()->second <= v) {
            s.erase(--s.end());
        }
    }
    cout << k << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/**
    Final exam tomorrow?
    Who cared.
*/