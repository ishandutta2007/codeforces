
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n, p[N], invp[N];

// bool check(int l, int r, int L) {
//     int pos = invp[L];
//     if(r < l) return true;
//     if(pos < l || pos > r) return false;
//     return check(pos + 1, r, L + 1) && check(l, pos - 1, L + r - pos + 1);
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> p[i];
            invp[p[i]] = i;
        }
        bool flag = true;
        for(int i = 2; i <= n; i++) {
            if(invp[i] != invp[i - 1] + 1 && invp[i - 1] < n && p[invp[i - 1] + 1] > i) {
                flag = false;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
}