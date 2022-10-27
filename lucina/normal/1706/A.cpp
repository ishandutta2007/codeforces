#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
char s[nax];
int n, m;
int a[nax];

void solve() {
    cin >> n >> m;
    for (int i = 1 ; i <= m ; ++ i) {
        s[i] = 'B';
    }

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        a[i] = min(a[i], m - a[i] + 1);
        if (s[a[i]] == 'A') {
            s[m - a[i] + 1] = 'A';
        } else s[a[i]] = 'A';
    }
    s[m + 1] = '\0';
    cout << s +  1 << '\n';


}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    rated div.2, quite a while though
*/