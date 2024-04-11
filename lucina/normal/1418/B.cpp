#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int l[nax];
int a[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    vector <int> b;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> l[i];
        if (!l[i]) {
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end());

    for (int i = 1 ; i <= n ; ++ i)
        if (!l[i]) a[i] = b.back(), b.pop_back();
    for (int i = 1 ; i <= n ; ++ i)
        cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    ZZZZZZZ
*/