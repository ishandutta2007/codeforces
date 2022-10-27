#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];


bool solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    if (n == 1) return true;
    for (int x = -1 ; x <= 1 ; ++ x) {
        int pos = a[1] + x;
        for (int j = 2 ; j <= n ; ++ j) {
            pos ++;
            if (!(pos <= a[j] + 1 && pos >= a[j] - 1)) break;
            if (j == n) return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}