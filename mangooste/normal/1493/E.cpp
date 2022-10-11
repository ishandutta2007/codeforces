#include <bits/stdc++.h>

using namespace std;

string add_one(string s) {
    assert(s != string(s.size(), '1'));
    int to_add = 1;
    for (int i = int(s.size()) - 1; i >= 0; i--) {
        int cur = s[i] - '0' + to_add;
        s[i] = '0' + cur % 2;
        to_add = cur > 1;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    string l, r;
    cin >> n;
    cin >> l >> r;
    if (r[0] != l[0]) {
        cout << string(n, '1') << '\n';
        return 0;
    }
    if (r == l) {
        cout << r << '\n';
        return 0;
    }
    if (r.back() == '1') {
        cout << r << '\n';
        return 0;
    }
    if (add_one(l) == r)
        cout << r << '\n';
    else
        cout << add_one(r) << '\n';
}