
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s[0] >> s[1] >> s[2];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int i2 = 2 - i, j2 = 2 - j;
            if(s[i][j] != s[i2][j2]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}