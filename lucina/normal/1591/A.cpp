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
    int sum = 1;
    sum += a[1];
    for (int i = 2 ; i <= n ; ++ i) {
        if (a[i]) {
            sum += a[i - 1] ? 5 : 1;
        } else {
            if (!a[i - 1]) {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << sum << '\n';
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