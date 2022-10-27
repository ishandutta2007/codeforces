#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        int x, y;
        cin >> x >> y;
        for (int i = 0 ; i <= x ; ++ i)
        for (int j = 0 ; j <= y ; ++ j) {
            if (x - i + y - j == i + j) {
                cout << i << ' ' << j << '\n';
                goto BAR;
            }
        }
        cout << "-1 -1\n";
        BAR:;
    }
}