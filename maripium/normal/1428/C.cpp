#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        string ans;
        for (char c : S) {
            if (ans.size() && c == 'B') {
                ans.pop_back();
            } else {
                ans += c;
            }
        }
        cout << ans.size() << '\n';
    }
}