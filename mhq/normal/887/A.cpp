#include <bits/stdc++.h>
using namespace std;
int num;
int ind = -1;
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        cout << "no";
        return 0;
    }
    for (int i = ind + 1; i < s.size(); i++) {
        if (s[i] == '0') {
            num++;
        }
    }
    if (num >= 6) {
        cout << "yes";
    }
    else cout << "no";
    return 0;
}