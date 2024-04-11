#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

bool solve() {
    int x, a[4];
    cin >> x;
    for (int i = 1 ; i <= 3 ; ++ i)  {
        cin >> a[i];
    }
    for (int i = 0 ; i < 2 ; ++ i) {
        x = a[x];
        if (x == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
/*
    Eduroundd
*/