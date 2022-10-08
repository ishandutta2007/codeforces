
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, q;
ll s[N], dif[N], l, r;

// s[0], s[0] + 1, s[0] + 2, ..., s[0] + r
// s[1], s[1] + 1, s[1] + 2, ..., s[1] + r
// min(r, s[1] - s[0]) + min(r, s[2] - s[1]) + min(r, s[3] - s[2])
// store list of differences s[i] - s[i - 1]
// sort the differences
// find prefix sum of differences until they are larger than r, then add r for the rest of them

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n);
    for(int i = 1; i < n; i++) {
        dif[i] = s[i] - s[i - 1];
    }
    sort(dif + 1, dif + n);
    s[0] = 0;
    for(int i = 1; i < n; i++) {
        s[i] = s[i - 1] + dif[i];
    }

    cin >> q;
    while(q--) {
        cin >> l >> r;
        r = r - l + 1;
        int idx = lower_bound(dif + 1, dif + n, r) - dif;
        ll num = s[idx - 1] + (n - idx + 1) * r;
        cout << num << " ";
    }
    cout << endl;
}