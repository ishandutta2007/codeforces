
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        stringstream ss;
        ll n2 = n;
        while(n > 0) {
            ss << (n % 3);
            n /= 3;
        }
        int last2 = -1;
        string s = ss.str();
        int len = s.length();
        for(int i = 0; i < len; i++) {
            if(s[i] == '2') last2 = i;
        }
        if(last2 == -1) {
            cout << n2 << endl;
        }else {
            int i = 0;
            for(i = 0; i < len && (i <= last2 || s[i] != '0'); i++) {
                s[i] = '0';
            }
            if(i == len) {
                s.push_back('1');
            }else {
                s[i] = '1';
            }
            len = s.length();
            for(int i = len - 1; i >= 0; i--) {
                n = 3 * n + (s[i] - '0');
            }
            cout << n << endl;
        }
    }
}