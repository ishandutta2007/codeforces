
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        bool a[2] = {false, false};
        for(char c : s) {
            a[c - '0'] = true;
        }
        string ans;
        if(a[0] && a[1]) {
            ans = "01";
        }else if(a[0]) {
            ans = "00";
        }else if(a[1]) {
            ans = "11";
        }
        for(int i = 0; i < n; i++) {
            cout << ans;
        }
        cout << '\n';
    }
}