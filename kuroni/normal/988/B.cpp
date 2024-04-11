#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
string s[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    sort(s + 1, s + n + 1, [](const string &u, const string &v) {
        return u.size() < v.size() || (u.size() == v.size() && u < v);
    });
    for (int i = 2; i <= n; i++) {
        if (s[i].find(s[i - 1]) == s[i].npos) {
            return cout << "NO\n", 0;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << s[i] << '\n';
    }
}