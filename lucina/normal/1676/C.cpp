#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;

/**
    Imagine array v_i - i
    The operation took place like
    0 -1 -2 -3 0 -1 -2 -3
    each zeros will be moved to next zero
    -1 -2 -3 0 -1 -2 -3 0
    and add 1 to everything
    0 -1 -2 0 0 -1 -2
    Well, it just shifting array to the left k times
*/
int n;
string s[nax];


int dif(string a, string b) {
    int res = 0;
    for (int i = 0 ; i < a.size() ; ++ i) {
        char u = a[i], v = b[i];
        res += min({abs(u - v)});
    }
    return res;
}

int m;
void solve() {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> s[i];
    int ans = 15131;
    for (int i = 1 ; i < n ; ++ i)
    for (int j = i + 1 ; j <= n ; ++ j)
        ans = min(ans, dif(s[i], s[j]));
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
        //cout << (solve() ? "YES" : "NO") << '\n';
    }
}