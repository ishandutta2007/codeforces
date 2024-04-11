#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;



void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    iota(a.begin(), a.end(), 1);
    reverse(a.begin(), a.end());
    if (n == 3) {
        cout << "-1\n";
        return;
    }

    if (n % 2) {
        for (int i = 2 ; i < n ; ++ i)
            a[i] = i - 1;
    }
    for (int i : a) cout << i << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}