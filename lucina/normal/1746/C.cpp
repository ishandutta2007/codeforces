#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int ans[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        ans[i] = 1;
    }
    vector <int> need[n + 1];

    for (int i = n ; i > 1 ; -- i) {
        if (a[i] < a[i - 1]) {
            need[a[i - 1] - a[i]].push_back(i);
        }
    }
    vector <int> carry;

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j : need[i]) {
            carry.push_back(j);
        }
        if (!carry.empty()) ans[i] = carry.back(), carry.pop_back();
        cout << ans[i] << ' ';
    }
    cout << '\n';

    assert(carry.empty());

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    Global round, GL

*/