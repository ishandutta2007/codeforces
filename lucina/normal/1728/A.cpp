#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

void solve() {
    int n;
    cin >> n;
    int mx = 0, idx = -1;
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        cin >> x;
        if (x > mx) {
            idx = i;
            mx = x;
        }
    }
    cout << idx << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}