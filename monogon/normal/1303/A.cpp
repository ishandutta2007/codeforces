
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        int m = n, M = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                m = min(m, i);
                M = max(M, i);
            }
        }
        if(m > M) {
            cout << 0 << endl;
        }else {
            int cnt = 0;
            for(int i = m; i < M; i++) {
                cnt += (s[i] == '0');
            }
            cout << cnt << endl;
        }
    }
}