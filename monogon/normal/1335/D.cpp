
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
string s[9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        for(int i = 0; i < 9; i++) {
            cin >> s[i];
        }
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << (s[i][j] == '9' ? '1' : s[i][j]);
            }
            cout << '\n';
        }
    }
}