#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
vector < pair < char, int > > get(string s) {
    int cur = 0;
    vector < pair < char, int > > ans;
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && s[i] != s[i - 1]) {
            ans.push_back(make_pair(s[i - 1], cur));
            cur = 1;
        }
        else {
            cur++;
        }
    }
    if (cur > 0) ans.push_back(make_pair(s.back(), cur));
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--) {
        string s, t;
        cin >> s >> t;
        auto ans1 = get(s);
        auto ans2 = get(t);
        if (ans1.size() != ans2.size()) {
            cout << "NO" << '\n';
        }
        else {
            bool ok = true;
            for (int i = 0; i < ans1.size(); i++) {
                if (ans1[i].second > ans2[i].second || ans1[i].first != ans2[i].first) {
                    ok = false;
                    break;
                }
            }
            if (ok) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}