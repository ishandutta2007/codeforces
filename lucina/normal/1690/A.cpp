#include<bits/stdc++.h>
using namespace std;
int a[3];

void solve() {
    int n;
    cin >> n;

    a[0] = n / 3;
    n -= n / 3;
    a[1] = n / 2;
    a[2] = n - n / 2;
    sort(a, a + 3, greater<int>());
    if (a[0] == a[1]) {
        a[0] += 1, a[2] -= 1;
    } else if (a[1] == a[2]) {
        a[0] += 1, a[2] -= 1;
    }
    cout << a[1] << ' ' << a[0]  << ' ' << a[2];
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}