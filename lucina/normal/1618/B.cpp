#include<bits/stdc++.h>
using namespace std;
string s[150];

void solve() {
    /**
        ab bc
    */
    int n;
    cin >> n;
    cin >> s[0];
    int incampat = -1;
    string res;
    res += s[0];
    for (int i = 1 ; i < n - 2 ; ++ i) {
        cin >> s[i];
        if (s[i][0] != s[i - 1][1]) {
            res += s[i][0];
            res += s[i][1];
        } else {
            res += s[i][1];
        }
    }
    if (res.size() != n) {
        res += 'b';
    }
    assert(res.size() == n);
    cout << res << '\n';

}

int main() {
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}