#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector <int> v;
    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] == '(' && s[r] == ')') {
            v.push_back(l), v.push_back(r), ++l, --r;
        }
        else {
            if (s[l] == ')') ++l;
            if (s[r] == '(') --r;
        }
    }
    if (v.empty()) cout << 0 << endl;
    else {
        cout << 1 << endl << v.size() << endl;
        sort(v.begin(), v.end());
        for (auto x: v) cout << x + 1 << ' '; cout << endl;
    }
    return 0;
}