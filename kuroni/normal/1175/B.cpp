#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    string s;
    cin >> n;
    long long ans = 0, MX = (1LL << 32) - 1;
    vector<long long> st = {1};
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s == "add") {
            if (st.back() == -1) {
                return cout << "OVERFLOW!!!", 0;
            }
            ans += st.back();
            if (ans > MX) {
                return cout << "OVERFLOW!!!", 0;
            }
        } else if (s == "end") {
            st.pop_back();
        } else {
            cin >> t;
            st.push_back(st.back() * t);
            if (st.back() > MX || st.back() < 0) {
                st.back() = -1;
            }
        }
    }
    cout << ans;
}