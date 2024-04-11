#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m;

void solve() {
    cin >> n >> m;
    vector <int> bar;

    for (int i = 1, k = 0 ; i <= m ; i += 2) {
        bar.push_back(0 ^ k);
        bar.push_back(1 ^ k);
        k ^= 1;
    }
    vector <int> foo = bar;
    for (int & x : foo) x ^= 1;
    auto print = [](vector <int> v) {
        for (int j : v) cout << j << ' ';
        cout << '\n';
    };
    for (int i = 1, k = 0 ; i <= n ; i += 2) {
        if (k % 2) {
            print(foo);
            print(bar);
        } else {
            print(bar);
            print(foo);
        }
        k ^= 1;
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}