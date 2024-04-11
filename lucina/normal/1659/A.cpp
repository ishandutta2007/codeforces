#include<bits/stdc++.h>
using namespace std;
int n, a, b;


void solve() {
    cin >> n >> a >> b;
    int k = b + 1;
    int d = a / k;
    int res = a - k * d;
    for (int i = 1 ; i <= b ; ++ i) {
        cout << string(d + (i <= res), 'R');
        a -= d + (i <= res);
        cout << 'B';
    }
    cout << string(a, 'R');
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}