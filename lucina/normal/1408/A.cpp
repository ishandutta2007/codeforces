#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax][3];

int ans[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cin >> n;

        for (int i = 0 ; i < n; ++ i)
            cin >> a[i][0];
        for (int i = 0 ; i < n ; ++ i)
            cin >> a[i][1];
        for (int i = 0 ; i < n ; ++ i)
            cin >> a[i][2];
        ans[0] = a[0][0];
        for (int i = 1 ; i < n ; ++ i) {
            int from = ans[i - 1];
            int to = i == n - 1 ? ans[0] : (1e9 + 7);

            for (int j = 0 ; j < 3 ; ++ j) {
                if (a[i][j] != from && a[i][j] != to) {
                    ans[i] = a[i][j];
                    break;
                }
            }
        }
        for (int i = 0 ; i < n ; ++ i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}
/*
    Good Luck
        -Lucina
*/