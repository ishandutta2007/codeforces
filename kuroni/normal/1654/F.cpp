#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> suf(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        suf[i] = s[i] - 'a';
    }
    for (int j = 0; j < n; j++) {
        vector<pair<pair<int, int>, int>> tmp;
        for (int i = 0; i < (1 << n); i++) {
            tmp.push_back({{suf[i], suf[i ^ (1 << j)]}, i});
        }
        sort(tmp.begin(), tmp.end());
        int cur = 0;
        for (int i = 0; i < (1 << n); i++) {
            if (i > 0 && tmp[i].first > tmp[i - 1].first) {
                cur++;
            }
            suf[tmp[i].second] = cur;
        }
    }
    int j = min_element(suf.begin(), suf.end()) - suf.begin();
    for (int i = 0; i < (1 << n); i++) {
        cout << s[i ^ j];
    }
}