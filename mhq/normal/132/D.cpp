#include <bits/stdc++.h>
using namespace std;
string s;
vector < int > ones;
vector < pair < int, int > > seg;
vector < pair < int, int > > ans;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (i > 0 && i + 1 < s.size()) {
                if (s[i - 1] == '1' && s[i + 1] == '1') {
                    if (i > 1 && s[i - 2] == '1') {
                        s[i] = '1';
                        ans.push_back(make_pair(i, -1));
                    }
                    else if (i + 2 < s.size() && s[i + 2] == '1') {
                        s[i] = '1';
                        ans.push_back(make_pair(i, -1));
                    }
                }
            }
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            ones.push_back(i);
        }
    }
    int l = ones[0];
    int r = ones[0];
    for (int i = 1; i < ones.size(); i++) {
        if (ones[i] == ones[i - 1] + 1) {
            r++;
        }
        else {
            seg.push_back(make_pair(l, r));
            l = ones[i];
            r = ones[i];
        }
    }
    seg.push_back(make_pair(l, r));
    for (int i = 0; i < seg.size(); i++) {
        if (seg[i].first == seg[i].second) {
            ans.push_back(make_pair(seg[i].first, 1));
        }
        else {
            ans.push_back(make_pair(seg[i].first, -1));
            ans.push_back(make_pair(seg[i].second + 1, 1));
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].second > 0) cout << "+2^" << ans[i].first << '\n';
        else cout << "-2^" << ans[i].first << '\n';
    }
    return 0;
}