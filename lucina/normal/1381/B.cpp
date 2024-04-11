#include<bits/stdc++.h>
using namespace std;
int const nax = 4010;
int n;
bool dp[nax];
int a[nax];

void solve () {
    cin >> n;
    for (int i = 1 ; i <= n + n ; ++ i)
        cin >> a[i];
    int mx = a[1];

    vector <int> ch;
    ch.push_back(1);

    for (int i = 1 ; i <= n + n; ++ i) {
        if (a[i] > mx) {
            ch.push_back(i);
        }
        mx = max(mx, a[i]);
    }

    ch.push_back(n + n + 1);

    vector <int> res;
    for (int i = 1 ; i < int(ch.size()) ; ++ i)
        res.push_back(ch[i] - ch[i - 1]);
    for (int i = 0 ; i <= n; ++ i)
        dp[i] = false;
    dp[0] = true;

    for (int i : res) {
      //  cout << i << ' ';
        for (int j = n ; j >= i ; -- j)
            dp[j] |= dp[j - i];
    }
   // cout << '\n';

    cout << (dp[n] ? "YES" : "NO") << '\n';
}

int main () {
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