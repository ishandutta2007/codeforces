// typing from phone

#include <bits/stdc++.h>
using namespace std;

int main() {
    int te, n;
    cin >> te;
    while(te--) {
        string s;
        cin >> n >> s;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            cnt += (s[i] == s[i - 1]);
        }
        cout << cnt / 2 << '\n';
    }
}