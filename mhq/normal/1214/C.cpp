#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s;
void check_good(string& p) {
    int bal = 0;
    for (auto c : p) {
        if (c == '(') bal++;
        else bal--;
        if (bal < 0)return;
    }
    if (bal != 0) return;
    cout << "Yes";
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tr; cin >> tr;
    cin >> s;
    int bal = 0;
    int frst = -1;
    int lst = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            bal++;
            lst = i;
        }
        else {
            bal--;
            if (frst == -1) frst = i;
        }
    }
    if (bal != 0) {
        cout << "No" << '\n';
        return 0;
    }
    string p1, p2;
    p1 += "(";
    for (int i = 0; i < s.size(); i++) {
        if (i != lst) {
            p1 += s[i];
        }
        if (i != frst) {
            p2 += s[i];
        }
    }
    p2 += ")";
    check_good(p1);
    check_good(p2);
    cout << "No";
    return 0;
}