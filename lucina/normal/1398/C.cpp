#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve () {
    cin >> n;
    static char s[nax];
    cin >> s + 1;

    for (int i = 1 ; i <= n ; ++ i)
        a[i] = s[i] - '0';
    map <int, int> naive;
    ++ naive[0];

    for (int i = 1 ; i <= n; ++ i) {
        a[i] += a[i - 1];
        ++ naive[a[i] - i];
    }

    long long res = 0;
    for (auto &it : naive) {
        int c = it.second;
        res += 1LL * c * (c - 1) / 2;
    }
    cout << res << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ; ) {
        solve();
    }
}