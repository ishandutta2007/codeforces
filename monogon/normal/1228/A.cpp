
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int l, r;
string s;

bool check(int x) {
    stringstream ss;
    ss << x;
    ss >> s;
    int n = s.length();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> l >> r;
    for(int i = l; i <= r; i++) {
        if(check(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}