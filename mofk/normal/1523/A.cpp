#include <bits/stdc++.h>

using namespace std;

string trans(string s) {
    string t = s;
    for (int i = 0; i < t.size(); ++i) {
        int a = (i > 0) && (s[i-1] == '1');
        int b = (i + 1 < s.size()) && (s[i+1] == '1');
        if (a + b == 1) t[i] = '1';
    }
    return t;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        for (int i = 0; i < m; ++i) {
            string t = trans(s);
            if (s == t) break;
            s = t;
        }
        cout << s << endl;
    }
    return 0;
}