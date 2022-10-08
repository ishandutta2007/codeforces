
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n;
string s;
int zeros[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += s[i] == '0';
            if(s[i] == '1') {
                cnt = 0;
            }
            zeros[i] = cnt;
        }

        int m = log2(n) + 1;
        int p = 2;
        int good = 0;
        for(int k = 1; k <= m; k++) {
            int num = 0;
            for(int i = 0; i < k; i++) {
                num = (num * 2) + (s[i] == '1');
            }
            for(int i = k; i < n; i++) {
                if(s[i - k] == '1' && num <= n && (k == num || (i - k - 1 >= 0 && zeros[i - k - 1] >= num - k))) {
                    good++;
                }
                num = (num * 2) + (s[i] == '1');
                num %= p;
            }
            if(s[n - k] == '1' && num <= n && (k == num || (n - k - 1 >= 0 && zeros[n - k - 1] >= num - k))) {
                good++;
            }
            p *= 2;
        }
        cout << good << endl;
    }
}