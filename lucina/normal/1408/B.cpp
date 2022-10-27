#include<bits/stdc++.h>
using namespace std;
int const nax = 128;
const int INF = 1e9;
int n, k;
int a[nax];
int b[nax];

int count_differ(int *a) {
    int ct = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        int j = i;
        while (j <= n && a[j] == a[i])
            ++ j;
        ct += 1;
        i = j - 1;
    }
    return ct;
}

void solve() {
    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];

    if (k == 1) {
        if (a[1] == a[n]) {
            cout << "1\n";
        } else cout << "-1\n";
        return;
    }

    int need = max(0, count_differ(a) - k);
    int can = k - 1;
    int ans = 1 + (need + can - 1) / can;

    cout << max(1, ans) << '\n';


}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/