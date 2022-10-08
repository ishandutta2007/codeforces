
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string s, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        bool flag = true;
        int i, j;
        cin >> s >> c;
        if(s < c) {
            cout << s << endl;
            goto endloop;
        }
        n = s.length();
        for(i = 0; i < n && flag; i++) {
            for(j = i + 1; j < n; j++) {
                if(s[i] > s[j]) {
                    flag = false;
                    swap(s[i], s[j]);
                    if(s < c) {
                        cout << s << endl;
                        goto endloop;
                    }
                    swap(s[i], s[j]);
                }
            }
        }
        cout << "---" << endl;
        endloop:;
    }
}