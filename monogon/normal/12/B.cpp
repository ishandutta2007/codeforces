
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    int n = s.length();
    sort(s.begin(), s.end());
    for(int i = 0; i < n; i++) {
        if(s[i] != '0') {
            swap(s[i], s[0]);
            break;
        }
    }
    cout << (s == t ? "OK" : "WRONG_ANSWER") << endl;
}