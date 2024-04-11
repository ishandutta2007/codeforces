
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
        cin >> n >> s;
        string a = "", b = "";
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(flag) {
                a.push_back('0');
                b.push_back(s[i]);
            }else if(s[i] == '0') {
                a.push_back('0');
                b.push_back('0');
            }else if(s[i] == '2') {
                a.push_back('1');
                b.push_back('1');
            }else {
                flag = true;
                a.push_back('1');
                b.push_back('0');
            }
        }
        cout << a << '\n' << b << '\n';
    }
}