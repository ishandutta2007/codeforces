
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q, n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        bool o = 0, z = 0;
        int off = 0;
        for(int i = 0; i < n; i++) {
            cin >> s;
            for(char c : s) {
                o ^= (c == '1');
                z ^= (c == '0');
            }
            off += (s.length() & 1);
        }
        if(off >= o + z) {
            cout << n << endl;
        }else {
            cout << n - 1 << endl;
        }
    }
}