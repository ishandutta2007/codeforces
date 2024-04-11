
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string s;
bool used[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        string keys = "";
        keys.push_back(s[0]);
        int j = 0;
        fill(used, used + 26, false);
        used[s[0] - 'a'] = true;
        for(int i = 1; i < n; i++) {
            if(s[i - 1] == s[i]) {
                cout << "NO" << endl;
                goto endloop;
            }
            if(keys.length() == 1) {
                keys.insert(0, 1, s[i]);
                if(used[s[i] - 'a']) {
                    cout << "NO" << endl;
                    goto endloop;
                }
                used[s[i] - 'a'] = true;
            }else if(j < (int) keys.length() - 1 && keys[j + 1] == s[i]) {
                j++;
            }else if(j > 0 && keys[j - 1] == s[i]) {
                j--;
            }else if(j == (int) keys.length() - 1) {
                keys.push_back(s[i]);
                if(used[s[i] - 'a']) {
                    cout << "NO" << endl;
                    goto endloop;
                }
                used[s[i] - 'a'] = true;
                j++;
            }else if(j == 0) {
                keys.insert(0, 1, s[i]);
                if(used[s[i] - 'a']) {
                    cout << "NO" << endl;
                    goto endloop;
                }
                used[s[i] - 'a'] = true;
            }else {
                cout << "NO" << endl;
                goto endloop;
            }
        }
        cout << "YES" << endl << keys;
        for(int i = 0; i < 26; i++) {
            if(!used[i]) {
                cout << (char) ('a' + i);
            }
        }
        cout << endl;
        endloop:;
    }
}