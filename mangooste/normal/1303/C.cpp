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
        string res = "";
        res.push_back(s[0]);
        vector<int> pos(26, -1);
        pos[s[0] - 'a'] = 0;
        int n = s.size();
        int cur = 0;
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (pos[s[i] - 'a'] == -1) {
                if (cur == (int)res.size() - 1) {
                    cur++;
                    res.push_back(s[i]);
                    pos[s[i] - 'a'] = cur;
                    continue;
                }
                if (cur == 0) {
                    for (auto i : res) {
                        pos[i - 'a']++;
                    }
                    res.push_back('a');
                    for (int i = (int)res.size() - 2; i >= 0; i--) {
                        swap(res[i], res[i + 1]);
                    }
                    res[0] = s[i];
                    pos[s[i] - 'a'] = 0;
                    continue;
                }
                ok = false;
                break;
            } else {
                if (abs(pos[s[i] - 'a'] - cur) < 2) {
                    cur = pos[s[i] - 'a'];
                    continue;
                }
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < 26; i++) {
            if (pos[i] == -1) {
                res.push_back('a' + i);
            }
        }
        cout << "YES\n";
        cout << res << '\n';
    }
}