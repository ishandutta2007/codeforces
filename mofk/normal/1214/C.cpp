#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    if (n & 1) return cout << "No" << endl, 0;
    int cur = 0, low = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') ++cur; else --cur;
        low = min(low, cur);
    }
    if (cur || low < -1) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    return 0;
}