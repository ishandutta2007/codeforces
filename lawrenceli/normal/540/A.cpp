#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    int ans = 0;
    for (int i=0; i<n; i++) ans += min(abs(s[i]-t[i]), 10-abs(s[i]-t[i]));
    cout << ans;
}