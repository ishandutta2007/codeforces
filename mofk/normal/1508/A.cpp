#include <bits/stdc++.h>

using namespace std;

bool have(const string &s, int c) {
    int z = 0;
    for (auto x: s) if (x - '0' == c) ++z; else --z;
    return z >= 0;
}

string solve(const string &a, const string &b, int c) {
    int n = a.size() / 2;
    int i = 0, j = 0;
    string ret;
    while (i < a.size() && j < a.size()) {
        if (a[i] == b[j]) {
            ret += a[i];
            ++i;
            ++j;
        }
        else if (a[i] - '0' == c) {
            ret += b[j];
            ++j;
        }
        else {
            ret += a[i];
            ++i;
        }
    }
    while (i < a.size()) ret += a[i], ++i;
    while (j < b.size()) ret += b[j], ++j;
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        string a[3];
        cin >> a[0] >> a[1] >> a[2];
        string ans;

        for (int i = 0; i < 3; ++i) for (int j = i + 1; j < 3; ++j) for (int c = 0; c < 2; ++c) if (have(a[i], c) && have(a[j], c))
            ans = solve(a[i], a[j], c);
        cout << ans << '\n';
    }
    return 0;
}