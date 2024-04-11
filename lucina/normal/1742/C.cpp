#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    char s[10][10];

    for (int i = 0 ; i < 8 ; ++ i)
        cin >> s[i];
    for (int i = 0 ; i < 8 ; ++ i) {
        if (count(s[i], s[i] + 8, 'R') == 8) {
            cout << "R\n";
            return;
        }
    }
    cout << "B\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}