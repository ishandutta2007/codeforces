
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const ll M = 1'000'000'007;
int t, n, x;
ll len;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> x >> s;
        n = s.length();
        len = 0;
        if(n > x) {
            s = s.substr(0, x);
            len = n - x;
            n = x;
        }
        for(int i = 0; i < x; i++) {
            ll suf = n - i - 1;
            ll add = ((s[i] - '0' - 1) * (len + suf)) % M;
            int j = 0;
            for(; j < add && n < x; j++, n++) {
                s.push_back(s[i + 1 + (j % suf)]);
            }
            len = ((len + add - j) % M + M) % M;
        }
        cout << (((n + len) % M + M) % M) << endl;
    }
}