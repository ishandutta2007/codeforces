#include<bits/stdc++.h>
using namespace std;
int n, a, b;
int p[128];
void solve() {
    cin >> n >> a >> b;
    int l = 0, r = n / 2;
    p[l++] = a;
    p[r++] = b;
    for (int i = n ; i >= 1 ; -- i) {
        if (i == a || i == b) continue;
        if (l < n / 2 && i >= a) {
            p[l ++] = i;
        } else if (r < n && i <= b) {
            p[r ++] = i;
        } else {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0 ; i < n ;++ i)
        cout << p[i] << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}