#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
string s;
int n, q;
char c;


void solve() {
    cin >> n >> c >> s;
    s += s;
    int last_g = -1;
    if (c == 'g') {
        cout << "0\n";
        return;
    }
    int ans = 0;

    for (int i = s.size() - 1 ; i >= 0 ; -- i) {
        if (s[i] == c) {
            if (last_g != -1) {
                ans = max(ans, last_g - i);
            }
        }
        if (s[i] == 'g') {
            last_g = i;
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