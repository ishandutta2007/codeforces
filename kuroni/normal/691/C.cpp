#include <bits/stdc++.h>
using namespace std;

string s, le, ri;
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int pos = s.find('.');
    if (pos == s.npos) {
        pos = s.size();
    }
    for (int i = 0; i < pos; i++) {
        le.push_back(s[i]);
    }
    for (int i = pos + 1; i < s.size(); i++) {
        ri.push_back(s[i]);
    }
    reverse(le.begin(), le.end());
    while (le.back() == '0') {
        le.pop_back();
    }
    reverse(le.begin(), le.end());
    reverse(ri.begin(), ri.end());
    if (!le.empty()) {
    while (le.size() > 1) {
        ri.push_back(le.back());
        le.pop_back();
        ans++;
    }
    } else {
        while (ri.back() == '0') {
            ri.pop_back();
            ans--;
        }
        le.push_back(ri.back());
        ri.pop_back();
        ans--;
    }
    reverse(ri.begin(), ri.end());
    while (!ri.empty() && ri.back() == '0') {
        ri.pop_back();
    }
    cout << le;
    if (!ri.empty()) {
        cout << "." << ri;
    }
    if (ans != 0) {
        cout << "E" << ans;
    }
}