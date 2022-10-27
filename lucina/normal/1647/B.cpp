#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
char s[1024][1024];
int n, m;

void solve() {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> s[i] + 1;
    for (int i = 1 ; i < n ; ++ i)
    for (int j = 1 ; j < m ; ++ j) {
        int sum = 0;
        for (int x = 0 ; x < 2 ; ++ x)
        for (int y = 0 ; y < 2 ; ++ y)
            sum += s[i + x][j + y] == '1';
        if (sum == 3) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}