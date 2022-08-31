#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
void bad() {
    cout << -1;
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int l = -1;
    int r = s.size();
    string t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[') {
            t += s[i];
            l = i;
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ']') {
            t += s[i];
            r = i;
            break;
        }
    }
    if (l == -1 || r == s.size()) bad();
    int l2 = -1;
    int r2 = s.size();
    for (int i = l; i <= r; i++) {
        if (s[i] == ':') {
            t += s[i];
            l2 = i;
            break;
        }
    }
    for (int i = r; i >= l; i--) {
        if (s[i] == ':') {
            t += s[i];
            r2 = i;
            break;
        }
    }
    if (l2 == -1 || r2 == s.size()) bad();
    if (l2 == r2) bad();
    for (int j = l2; j <= r2; j++) {
        if (s[j] == '|') t += s[j];
    }
    cout << t.size();
    return 0;
}