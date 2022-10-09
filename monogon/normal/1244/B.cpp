
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> str;
        int m1 = n, m2 = -1;
        for(int i = 0; i < n; i++) {
            if(str[i] == '1') {
                m1 = min(m1, i);
                m2 = max(m2, i);
            }
        }
        cout << max(n, max(2 * (n - m1), 2 * (m2 + 1))) << endl;
    }
}