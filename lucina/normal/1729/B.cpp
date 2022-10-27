#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
string s;


void solve() {
    cin >> n >> s;
    string ans;
    for (int i = 0 ; i < n ; ++ i) {
        assert(s[i] > '0');
        if (s[i] >= '3') {
            ans += 'a' + s[i] - '1';
            continue;
        }
        if (i + 2 < n && s[i + 2] == '0') {
            /**
                xy0
            */
            if (i + 3 < n && s[i + 3] == '0') {
                ans += 'a' + s[i] - '1';
                continue;
            } else {
                ans += 'a' + ((s[i] - '0') * 10 + (s[i + 1] - '0')) - 1;
                i += 2;
                continue;
            }
        } else {
            ans += 'a' + s[i] - '1';
        }
    }
    cout << ans << '\n';
}

int main() {

    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }

}