
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string s;

bool check(int d) {
    int i = 0, j = d;
    while(i < j && i <= n) {
        i++;
        if(i <= n && s[i - 1] == 'R') {
            j = max(j, i + d);
        }
    }
    return i == n + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        int l = 0, r = n + 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(check(m)) {
                r = m;
            }else {
                l = m + 1;
            }
        }
        cout << l << endl;
    }
}