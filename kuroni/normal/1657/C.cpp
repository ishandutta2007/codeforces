#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        reverse(s.begin(), s.end());
        int cnt = 0, ans = 0;
        while (!s.empty()) {
            ans = 1; 
            char c = s.back(); s.pop_back();
            if (c == '(') {
                if (!s.empty()) {
                    s.pop_back();
                    cnt++;
                    ans = 0;
                }
            } else {
                while (!s.empty() && s.back() == '(') {
                    s.pop_back();
                    ans++;
                }
                if (!s.empty() && s.back() == ')') {
                    s.pop_back();
                    cnt++;
                    ans = 0;
                }
            }
        }
        cout << cnt << " " << ans << '\n';
    }
}