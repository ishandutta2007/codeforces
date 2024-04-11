#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string a;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' + 1 == prev) a += "0";
            else a += "1";
            prev = s[i] - '0' + a[i] - '0';
        }
        cout << a << endl;
    }
}