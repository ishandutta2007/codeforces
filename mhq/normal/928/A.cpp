#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e5 + 10;
int n;
string s;
string t[maxN];
int get(char x) {
    if (x >= '0' && x <= '9') return x - '0';
    if (x >= 'a' && x <= 'z') return get((char)(x + 'A' - 'a'));
    if (x == '_') return -1;
    if (x == 'O') return 0;
    if (x == 'I') return 1;
    if (x == 'L') return 1;
    return (x - 'A') + 30;
}
bool check(string s, string t) {
    if (s.size() != t.size()) return false;
    for (int i = 0; i < s.size(); i++) {
        if (get(s[i]) != get(t[i])) return false;
    }
    return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> s;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) {
        if (check(s, t[i])) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}