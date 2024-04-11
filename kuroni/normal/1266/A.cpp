#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> s;
        int ev = 0, ze = 0, to = 0;
        for (char &c : s) {
            if ((c - '0') % 2 == 0) {
                ev++;
            }
            if (c == '0') {
                ze++;
            }
            (to += (c - '0')) %= 3;
        }
        if (ze > 0 && ev > 1 && to % 3 == 0) {
            cout << "red\n";
        } else {
            cout << "cyan\n";
        }
    }
}