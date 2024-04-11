#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
    int n, m;
    string s, t;
    cin >> n >> m;
    cin >> s >> t;
    if (s == t) {
        cout << "YES";
        return 0;
    }
    int ind = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        cout << "NO";
        return 0;
    }
    if (s.size() - 1 > t.size()) {
        cout << "NO";
        return 0;
    }
    if (s.substr(0, ind) != t.substr(0, ind)) {
        cout << "NO";
        return 0;
    }
    if (s.substr(ind + 1, s.size() - ind - 1) != t.substr(t.size() - s.size() + ind + 1, s.size() - ind - 1)) {
        cout << "NO";
    }
    else cout << "YES";
    return 0;
}