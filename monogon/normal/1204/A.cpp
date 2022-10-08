
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    int n = s.length();
    int k = (n + 1) / 2;
    int i = 1;
    for(i = 1; i < n; i++) {
        if(s[i] == '1') {
            break;
        }
    }
    if(i == n && n % 2 == 1) k--;
    cout << k << endl;
}