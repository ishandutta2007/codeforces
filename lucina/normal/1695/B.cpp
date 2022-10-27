#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];

void solve() {
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    if (n % 2) {
        cout << "Mike" << '\n';
        return;
    }
    int mn = *min_element(a + 1, a + 1 + n);
    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] == mn) {
            cout << ((i % 2) ? "Joe" : "Mike") << '\n';
            return;
        }
    }



}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}