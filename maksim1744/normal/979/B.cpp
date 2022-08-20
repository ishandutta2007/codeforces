/*
    31.10.2018 20:57:34
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector< string > v(3);
    cin >> v[0] >> v[1] >> v[2];
    vector< pair< int, int > > ans(3);
    for (int i = 0; i < 3; ++i) {
        ans[i].second = i;
        string s = v[i];
        vector< int > cnt(52, 0);
        for (auto c : s) {
            if ('a' <= c && c <= 'z') {
                ++cnt[c - 'a'];
            } else {
                ++cnt[c - 'A' + 26];
            }
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        if (mx < s.length()) {
            ans[i].first = min((int)s.length(), mx + n);
        } else {
            if (n == 1) {
                ans[i].first = max(1, mx - 1);
            } else {
                ans[i].first = mx;
            }
        }
    }
    sort(ans.begin(), ans.end());
    if (ans[1].first == ans[2].first) {
        cout << "Draw\n";
    } else if (ans[2].second == 0) {
        cout << "Kuro\n";
    } else if (ans[2].second == 1) {
        cout << "Shiro\n";
    } else {
        cout << "Katie\n";
    }
    return 0;
}