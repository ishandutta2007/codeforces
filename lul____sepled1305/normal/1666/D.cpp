#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)

string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        map<char, int> cnt;
        cin >> s >> t;
        for (char c : s) cnt[c]++;
        bool bad = false;
        for (char c : t) {
            cnt[c]--;
            bad |= cnt[c] < 0;
        }
        if(bad) {
            cout << "NO\n";
            continue;
        }

        string res;
        for (char c : s) {
            if(cnt[c] > 0) {
                cnt[c]--;
            } else {
                res.push_back(c);
            }
        }
        cout << (res == t ? "YES" : "NO") << '\n';
    }
}