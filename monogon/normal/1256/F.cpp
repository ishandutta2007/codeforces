
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q, n, cnt[26], cnt2[26];
string s, t;

bool inv(string s) {
    int n = s.length();
    fill(cnt, cnt + 26, 0);
    bool tot = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < s[i] - 'a'; j++) {
            tot ^= cnt[j];
        }
        cnt[s[i] - 'a']++;
    }
    return tot;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n >> s >> t;
        fill(cnt, cnt + 26, 0);
        fill(cnt2, cnt2 + 26, 0);
        for(char c : s) cnt[c - 'a']++;
        for(char c : t) cnt2[c - 'a']++;
        bool b = false;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] != cnt2[i]) {
                cout << "NO" << endl;
                goto endloop;
            }
            if(cnt[i] >= 2) b = true;
        }
        cout << ((b || inv(s) == inv(t)) ? "YES" : "NO") << endl;
        endloop:;
    }
}