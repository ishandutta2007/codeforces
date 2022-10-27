#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0 ; i < s.size() ;) {
        int j = i;
        set <char> setik;
        while (j < s.size()) {
            setik.insert(s[j]);
            if (setik.size() > 3) break;
            j += 1;
        }
        ans += 1;
        i = j;
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