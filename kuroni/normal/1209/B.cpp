#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, ans = 0, a[N], b[N];
string s;

int solve(int t) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (t < b[i]) {
            cnt += (s[i] == '1');
        } else {
            int fl = ((t - b[i]) / a[i]) % 2;
            cnt += (s[i] == fl + '0');
        }
    }
    return cnt;
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i <= 1000; i++) {
        ans = max(ans, solve(i));
    }
    cout << ans;
}