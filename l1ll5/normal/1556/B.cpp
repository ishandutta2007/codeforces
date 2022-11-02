#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 100000 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int cnt0 = 0, cnt1 = 0;
        for (int& x : a) {
            cin >> x;
            x %= 2;
            if (x == 0) cnt0++;
            else cnt1++;
        }
        if (abs(cnt0 - cnt1) > 1) {
            cout << "-1\n";
            continue;
        }
        int here = 0;
        LL sum = 0;
        LL ans = 1e18;

        if (cnt0 >= cnt1) {
            here = 0, sum = 0;
            for (int i = 0; i < n; i += 1) {
                if (a[i] == 0) {
                    sum += abs(i - here);
                    here += 2;
                }
            }
            ans = min(ans, sum);
        }

        if (cnt1 >= cnt0) {
            here = 0, sum = 0;
            for (int i = 0; i < n; i += 1) {
                if (a[i] == 1) {
                    sum += abs(i - here);
                    here += 2;
                }
            }
            ans = min(ans, sum);
        }

        cout << ans << '\n';
    }
}