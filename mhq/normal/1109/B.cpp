#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxN = 3 * (int)1e5 + 100;
int f[(1 << 20) + 10][2];
void solve(string s) {
    if (s.size() % 2 == 1) {
        cout << 2;
        return ;
    }
    string t;
    for (int i = 0; i < s.size() / 2; i++) {
        t += s[i];
        if (s[i] != s[s.size() / 2 - i - 1]) {
            cout << 1;
            exit(0);
        }
    }
    solve(t);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    bool ok = false;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[0]) {
            ok = true;
            break;
        }
    }
    if (!ok) {
        cout << "Impossible";
        return 0;
    }
    solve(s);
}