#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, x;
int a[nax];
int b[nax];

bool solve() {
    cin >> n >> x;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i], b[i] = a[i];
    int cnt = 0;
    sort(b + 1, b + 1 + n);
    for (int i = n - x + 1 ; i <= x ; ++ i) {
        if (b[i] != a[i]) return false;
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
    Well, such a long time from last div.2 round
*/