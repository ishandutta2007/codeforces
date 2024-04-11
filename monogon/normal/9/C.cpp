
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            ans += (1 << (n - i - 1));
        }else if(s[i] > '1') {
            ans += (1 << (n - i)) - 1;
            break;
        }
    }
    cout << ans << endl;
}