#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];

void solve() {
    cin >> n;
    int cnt = 0;
    vector <int> f;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        b[i] = a[i];
        if (i > 1 && a[i] == a[i - 1]) cnt += 1, f.push_back(i - 1);
    }
    if (cnt <= 1) {
        cout << 0 << '\n';
        return;
    }
    bool ok = true;
    for (int i = 1 ; i < f.size() ; ++ i) {
        if (f[i] != f[i - 1] + 1) ok = false;
    }
    if (!ok) {
        cout << f.back() - f[0] - 1 << '\n';
    } else {
        int x = f.size();
        if (x <= 3) x = 1;
        else x = x - 2;
        cout << x << '\n';
    }
}

int main() {
    int T;
    cin.tie(0)->sync_with_stdio(false);
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    long time no rated round
*/