#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

string canonical(string s) {
    for (;;) {
        auto pos = s.find("kh");
        if (pos == string::npos)
            break;
        s.erase(pos, 1);
    }
    for (;;) {
        auto pos = s.find("u");
        if (pos == string::npos)
            break;
        s.insert(pos + 1, "o");
        s[pos] = 'o';
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<string> was;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        was.insert(canonical(s));
    }
    cout << was.size() << endl;
}