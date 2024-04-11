#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];

bool solve() {
    cin >> n;
    for (int i = 0 ; i < n ; ++ i)
        cin >> a[i];

    for (int i = 0 ; i < n ; ++ i)
        cin >> b[i];

    for (int i = 0 ; i < n ; ++ i) {
        int mx_nxt = b[(i + 1) % n];
        if (a[i] > b[i]) return false;
        if (b[i] > mx_nxt + 1 && a[i] != b[i]) return false;
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