#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    string s, t;
    cin >> s >> t;
    for (char c : t) {
        if (count(s.begin(), s.end(), c) == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    vector<pair<int, int>> ans;
    for (int i = 0; i < t.size();) {
        int maxLen = 0;
        int maxJ = 0;
        bool rev = false;
        for (int j = 0; j < s.size(); ++j) {
            int len = 0;
            for (int k = 0; i + k < t.size() && j + k < s.size(); ++k) {
                if (t[i + k] == s[j + k]) {
                    ++len;
                } else {
                    break;
                }
            }
            if (len > maxLen) {
                maxLen = len;
                maxJ = j;
            }
        }
        
        
        for (int j = 0; j < s.size(); ++j) {
            int len = 0;
            for (int k = 0; i + k < t.size() && j - k >= 0; ++k) {
                if (t[i + k] == s[j - k]) {
                    ++len;
                } else {
                    break;
                }
            }
            if (len > maxLen) {
                maxLen = len;
                maxJ = j;
                rev = true;
            }
        }
        
        if (rev) {
            ans.push_back({maxJ + 1, maxJ - maxLen + 2});
        } else {
            ans.push_back({maxJ + 1, maxJ + maxLen});
        }
        
        i += maxLen;
    }
    
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first << ' ' << p.second << endl;
    }
    
    return 0;
}