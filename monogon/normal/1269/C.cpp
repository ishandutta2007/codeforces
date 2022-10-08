
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, k;
string s, s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    for(int i = 0; i < n; i++) {
        s2.push_back(s[i % k]);
    }
    cout << n << endl;
    if(s <= s2) {
        cout << s2 << endl;
        return 0;
    }
    int c = 1;
    for(int i = k - 1; i >= 0; i--) {
        int d = s[i] - '0';
        int res = (d + c) % 10;
        c = (d + c) / 10;
        s[i] = '0' + res;
    }
    s2.clear();
    for(int i = 0; i < n; i++) {
        s2.push_back(s[i % k]);
    }
    cout << s2 << endl;
}