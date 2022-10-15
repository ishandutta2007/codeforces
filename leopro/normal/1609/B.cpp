#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> abc;
    for (int i = 0; i + 2 < s.size(); ++i) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') abc.insert(i);
    }
    for (int j = 0; j < q; ++j) {
        int index;
        char c;
        cin >> index >> c;
        s[--index] = c;
        for (int i = index - 2; i <= index; ++i) {
            if (i < 0 || i + 2 >= s.size()) continue;
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') abc.insert(i); else abc.erase(i);
        }
        cout << abc.size() << '\n';
    }
}