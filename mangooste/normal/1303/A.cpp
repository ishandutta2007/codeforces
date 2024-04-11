#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using ll = long long;
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int pos = -1;
        int n = s.size();
        int res = 0;
        bool was = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                was = true;
                if (pos != -1) {
                    res += i - pos;
                    pos = -1;
                }
            } else {
                if (pos == -1 && was) {
                    pos = i;
                }
            }
        }
        cout << res << '\n';
    }
}