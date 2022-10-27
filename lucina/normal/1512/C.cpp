#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 5;
int a, b;
string s;

void solve() {
    cin >> a >> b >> s;
    int n = a + b;
    #define bk(j) (n - j - 1)
    vector <int> marked;
    bool un = false;

    for (int i = 0 ; i < n ; ++ i) {
        if (i == bk(i)) {
            if (s[i] == '?') un = true;
            else if (s[i] == '0') a -= 1;
            else if (s[i] == '1') b -= 1;
            break;
        }
        if (i >= bk(i)) break;
        if (s[i] == s[bk(i)]) {
            if (s[i] == '?') marked.push_back(i);
            else if (s[i] == '0') a -= 2;
            else if (s[i] == '1') b -= 2;
        } else {
            if (s[i] != '?' && s[bk(i)] != '?') return cout << "-1\n", void();
            char ret = s[i] ^ s[bk(i)] ^ '?';
            s[i] = s[bk(i)] = ret;
            if (ret == '0') a -= 2;
            else if (s[i] == '1') b -= 2;
        }
    }
    if (a < 0 || b < 0) return cout << "-1\n", void();
    if (un && a % 2) a -= 1, un = false, s[n / 2] = '0';
    if (un && b % 2) b -= 1, un = false, s[n / 2] = '1';
    if (un) return cout << "-1\n", void();

    for (int j : marked) {
        if (a > 0) s[j] = s[bk(j)] = '0', a -= 2;
        else if (b > 0) s[j] = s[bk(j)] = '1', b -= 2;
        else return cout << "-1\n", void();
    }
    if (a != 0 || b != 0) return cout << "-1\n", void();
    cout << s << '\n';
}

int main() {


    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;
    for (int _ = 1 ; _ <= T ; ++ _) {
        solve();
    }

}