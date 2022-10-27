#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    vector <int> ans;
    for (int i = 1 ; i <= n ;) {
        int j = i;
        while (j <= n && a[j] == a[i]) j += 1;
        if (j - i == 1) return cout << "-1\n", void();
        for (int x = 0 ; x < j - i ; ++ x) {
            ans.push_back(i + (x + 1) % (j - i));
        }
        i = j;
    }
    for (int u : ans) cout << u << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ; ) {
        solve();
    }
}