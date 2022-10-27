#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
int n;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        int n;
        cin >> n;
        cout << 1 << ' ' << n << ' ';
        for (int j = 3 ; j < n ; ++ j) {
            cout << j << ' ';
        }
        cout << 2 << '\n';
    }




}